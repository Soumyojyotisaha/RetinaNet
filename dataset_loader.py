import os
import pandas as pd
import cv2
import torch
from torch.utils.data import Dataset
from torchvision import transforms

class CustomDataset(Dataset):
    def __init__(self, csv_file, img_dir, transform=None):
        self.annotations = pd.read_csv(csv_file)
        self.img_dir = img_dir
        self.transform = transform

    def __len__(self):
        return len(self.annotations)

    def __getitem__(self, idx):
        img_path = os.path.join(self.img_dir, self.annotations.iloc[idx, 0])
        image = cv2.imread(img_path)

        if image is None:
            raise FileNotFoundError(f"Error: Image not found at {img_path}")

        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        if self.transform:
            image = self.transform(image)

        target = {
            "boxes": torch.tensor(self.annotations.iloc[idx, 1:5].values, dtype=torch.float32),
            "labels": torch.tensor([1], dtype=torch.int64)
        }

        return image, target

# Set correct paths
csv_file = r"D:\test python\retinanet_annotations.csv"  # Use correct CSV filename
img_dir = r"D:\test python\dataset\images"  # Use correct images folder path

# Example transform
transform = transforms.Compose([
    transforms.ToTensor(),
])

# Load dataset
dataset = CustomDataset(csv_file=csv_file, img_dir=img_dir, transform=transform)
print(f"Dataset loaded with {len(dataset)} samples")


https://lucid.app/lucidchart/9b09a0fc-a501-40ee-9112-feb193150b61/edit?viewport_loc=250%2C915%2C2108%2C1006%2C0_0&invitationId=inv_b1165f96-48e3-40d2-a7b0-ea80f041ba0c 
