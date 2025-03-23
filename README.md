# RetinaNet - AI-Driven Branding Identity Verification

## 📌 Project Overview
This project leverages RetinaNet for detecting branding elements such as logos, colors, fonts, and UI components. It is part of the **The Brand Code (TBD)** initiative, aimed at automating branding guideline verification using computer vision and web scraping.

## 🚀 Features
- **Object Detection**: Uses RetinaNet to detect branding elements.
- **Automated Verification**: Integrates with CI/CD pipelines for compliance checking.
- **Efficient Model Training**: Supports fine-tuning on custom datasets.
- **Evaluation Metrics**: Computes mAP, precision, recall, and loss trends.
- **Visualization**: Plots training loss and accuracy.

## 📂 Repository Structure
```
📦 RetinaNet
├── 📁 data                # Dataset files
├── 📁 models              # Trained models and checkpoints
├── 📁 scripts             # Training, evaluation, and reporting scripts
├── generate_report.py     # Script to visualize training metrics
├── train.py               # Model training script
├── evaluate.py            # Model evaluation script
├── requirements.txt       # Dependencies
└── README.md              # Project documentation
```

## 🔧 Installation
```bash
# Clone the repository
git clone https://github.com/Soumyojyotisaha/RetinaNet.git
cd RetinaNet

# Install dependencies
pip install -r requirements.txt
```

## 📊 Training the Model
```bash
python train.py --epochs 10 --batch-size 8 --lr 0.001 --dataset data/train
```

## 📈 Evaluating the Model
```bash
python evaluate.py --model models/retinanet_latest.pth --dataset data/test
```

## 📉 Generating Reports
```bash
python generate_report.py
```

## 🔍 Example Outputs
```
📊 Training Loss Summary:
   🔹 Final Loss: 0.1527
   🔹 Min Loss: 0.1285
   🔹 Max Loss: 0.8415
   🔹 Mean Average Precision (mAP): 91.64%
```

## 🛠️ Troubleshooting
- **GitHub File Size Limit Error:** If you face issues with large `.pth` files, use Git Large File Storage (LFS):
  ```bash
  git lfs install
  git lfs track "*.pth"
  git add .gitattributes
  git add models/retinanet_latest.pth
  git commit -m "Track large model files"
  git push origin main
  ```

## 🤝 Contributors
- **Soumyojyoti Saha** ([@Soumyojyotisaha](https://github.com/Soumyojyotisaha))
- **Kuriakose Rishaan Jacob**
- **Sridharan Sriram**
- **Prajapat Saumyaa**

## 📜 License
This project is licensed under the MIT License. See `LICENSE` for details.

---
Feel free to contribute or reach out for collaboration! 🚀
