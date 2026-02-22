import os
import xml.etree.ElementTree as ET

# -----------------------------
# Configuration
# -----------------------------
FEATURE_LABELS = ["rms", "total_fft_energy"]
LABEL_TRACK_NAME = "imbalance"

# -----------------------------
# Update a single .imsession file
# -----------------------------
def update_imsession(file_path):
    print(f"Processing: {file_path}")

    tree = ET.parse(file_path)
    root = tree.getroot()
    modified = False

    for track in root.findall(".//Track"):
        track_type = track.get("type")

        # -----------------------------
        # Update IMU Data Track
        # -----------------------------
        if track_type == "datacsv":
            shape = track.find("Shape")
            if shape is None:
                shape = ET.SubElement(track, "Shape")

            axis = shape.find("Axis")
            if axis is None:
                axis = ET.SubElement(shape, "Axis")

            axis.set("name", "Axis")
            axis.set("size", str(len(FEATURE_LABELS)))

            # Remove old labels
            for label in list(axis):
                axis.remove(label)

            # Add correct feature labels
            for idx, name in enumerate(FEATURE_LABELS):
                lbl = ET.SubElement(axis, "Label")
                lbl.set("index", str(idx))
                lbl.text = name

            modified = True

        # -----------------------------
        # Update Label Track
        # -----------------------------
        elif track_type == "labelcsv":
            shape = track.find("Shape")
            if shape is None:
                shape = ET.SubElement(track, "Shape")

            axis = shape.find("Axis")
            if axis is None:
                axis = ET.SubElement(shape, "Axis")

            axis.set("name", "Labels")
            axis.set("size", "1")

            # Remove old labels
            for label in list(axis):
                axis.remove(label)

            # Add correct label
            lbl = ET.SubElement(axis, "Label")
            lbl.set("index", "0")
            lbl.text = LABEL_TRACK_NAME

            modified = True

    if modified:
        tree.write(file_path, encoding="UTF-8", xml_declaration=True)
        print("  → Updated")
    else:
        print("  → No changes needed")

# -----------------------------
# Process all folders
# -----------------------------
def process_all(base_dir="."):
    for root_dir, dirs, files in os.walk(base_dir):
        for file in files:
            if file.endswith(".imsession"):
                file_path = os.path.join(root_dir, file)
                try:
                    update_imsession(file_path)
                except Exception as e:
                    print(f"  → Error in {file_path}: {e}")

    print("\nAll .imsession files processed ✅")

# -----------------------------
# Run
# -----------------------------
if __name__ == "__main__":
    process_all(".")