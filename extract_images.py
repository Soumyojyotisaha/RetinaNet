import fitz  # PyMuPDF
import os
import cv2
import numpy as np

# List of PDF files to process
pdf_files = ["Brand Quick Reference Guide (1).pdf", "Brand Quick Reference Guide.pdf"]

# Output parent folder
output_parent_folder = "extracted_images"
os.makedirs(output_parent_folder, exist_ok=True)

# Process each PDF
for pdf_file in pdf_files:
    pdf_name = os.path.splitext(pdf_file)[0]  # Extract name without extension
    output_folder = os.path.join(output_parent_folder, pdf_name)  # Create subfolder for each PDF
    os.makedirs(output_folder, exist_ok=True)

    # Open the PDF
    doc = fitz.open(pdf_file)
    image_count = 0

    # Iterate through pages and extract images
    for page_num in range(len(doc)):
        for img_index, img in enumerate(doc[page_num].get_images(full=True)):
            xref = img[0]
            base_image = doc.extract_image(xref)
            image_bytes = base_image["image"]

            # Convert bytes to image array
            image_np = np.frombuffer(image_bytes, dtype=np.uint8)
            image = cv2.imdecode(image_np, cv2.IMREAD_COLOR)

            # Save image in PNG format inside respective subfolder
            image_filename = f"{output_folder}/page_{page_num+1}_img_{img_index+1}.png"
            cv2.imwrite(image_filename, image)

            image_count += 1
            print(f"Extracted: {image_filename}")

    print(f"✅ Total Images Extracted from {pdf_file}: {image_count}")
