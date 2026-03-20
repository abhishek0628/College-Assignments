import cv2
import numpy as np
import matplotlib.pyplot as plt
import os


# Create output folder if not present
if not os.path.exists("output"):
    os.makedirs("output")


# -------------------------
# 1a) Read image
# -------------------------

img = cv2.imread("input/photo.jpg", cv2.IMREAD_GRAYSCALE)

if img is None:
    print("Image not found in input folder")
    exit()

img = cv2.resize(img,(256,256))

plt.imshow(img,cmap='gray')
plt.title("Original Image")
plt.savefig("output/original.png")
plt.close()


# -------------------------
# 1b) Read portion
# -------------------------

portion = img[50:150,50:150]

plt.imshow(portion,cmap='gray')
plt.title("Image Portion")
plt.savefig("output/portion.png")
plt.close()


# -------------------------
# 1c) Add constant
# -------------------------

constant = 50
portion_added = portion + constant
portion_added = np.clip(portion_added,0,255)

plt.imshow(portion_added,cmap='gray')
plt.title("Portion after adding constant")
plt.savefig("output/portion_added.png")
plt.close()


# -------------------------
# 1d) Modify full image
# -------------------------

img_modified = img.copy()
img_modified[50:150,50:150] = portion_added

plt.imshow(img_modified,cmap='gray')
plt.title("Whole Image after modification")
plt.savefig("output/modified_image.png")
plt.close()


# -------------------------
# 1e) Multiply portion
# -------------------------

constants = [0.1,0.5,1.0,1.5,2.0]

for c in constants:

    temp = img.copy()

    part = temp[50:150,50:150] * c
    part = np.clip(part,0,255)

    temp[50:150,50:150] = part

    plt.imshow(temp,cmap='gray')
    plt.title(f"Multiplier {c}")
    plt.savefig(f"output/multiplier_{c}.png")
    plt.close()


# -------------------------
# 1f) Visible watermark
# -------------------------

watermark = np.zeros((256,256),dtype=np.uint8)

cv2.putText(watermark,"Abhishek Kumar",(20,120),
            cv2.FONT_HERSHEY_SIMPLEX,0.7,255,2)

cv2.putText(watermark,"16-03-2026",(60,180),
            cv2.FONT_HERSHEY_SIMPLEX,0.7,255,2)

visible = cv2.addWeighted(img,0.8,watermark,0.2,0)

plt.imshow(visible,cmap='gray')
plt.title("Visible Watermark")
plt.savefig("output/visible_watermark.png")
plt.close()


# -------------------------
# 1g) Invisible watermark
# -------------------------

embedded = img.copy()

for i in range(256):
    for j in range(256):

        bit = watermark[i,j] >> 7
        embedded[i,j] = (img[i,j] & 254) | bit


extracted = np.zeros((256,256),dtype=np.uint8)

for i in range(256):
    for j in range(256):

        extracted[i,j] = (embedded[i,j] & 1) * 255


plt.imshow(extracted,cmap='gray')
plt.title("Extracted Watermark")
plt.savefig("output/extracted_watermark.png")
plt.close()


# -------------------------
# 1h) Thresholding
# -------------------------

_, binary = cv2.threshold(img,127,255,cv2.THRESH_BINARY)

plt.imshow(binary,cmap='gray')
plt.title("Binary Image")
plt.savefig("output/binary.png")
plt.close()


# ======================================================
# 2. Filtering Operations
# ======================================================


# Custom convolution function

def convolution(image,kernel):

    m,n = image.shape
    k = kernel.shape[0]

    pad = k//2
    padded = np.pad(image,pad)

    output = np.zeros_like(image)

    for i in range(m):
        for j in range(n):

            region = padded[i:i+k,j:j+k]
            value = np.sum(region*kernel)

            output[i,j] = np.clip(value,0,255)

    return output


# -------------------------
# 2i) Low pass filtering
# -------------------------

kernel3 = np.ones((3,3))/9
kernel5 = np.ones((5,5))/25

low3 = convolution(img,kernel3)
low5 = convolution(img,kernel5)

plt.imshow(low3,cmap='gray')
plt.title("Low Pass 3x3")
plt.savefig("output/lowpass_3x3.png")
plt.close()

plt.imshow(low5,cmap='gray')
plt.title("Low Pass 5x5")
plt.savefig("output/lowpass_5x5.png")
plt.close()


# -------------------------
# 2ii) Sobel
# -------------------------

sobelx = np.array([[-1,0,1],
                   [-2,0,2],
                   [-1,0,1]])

sobely = np.array([[-1,-2,-1],
                   [0,0,0],
                   [1,2,1]])

gx = convolution(img,sobelx)
gy = convolution(img,sobely)

sobel = np.sqrt(gx**2 + gy**2)
sobel = np.clip(sobel,0,255)

plt.imshow(sobel,cmap='gray')
plt.title("Sobel Edge Detection")
plt.savefig("output/sobel.png")
plt.close()


# -------------------------
# Laplacian
# -------------------------

lap = np.array([[0,-1,0],
                [-1,4,-1],
                [0,-1,0]])

laplacian = convolution(img,lap)

plt.imshow(laplacian,cmap='gray')
plt.title("Laplacian")
plt.savefig("output/laplacian.png")
plt.close()


# -------------------------
# 2iii) Gaussian noise
# -------------------------

noise = np.random.normal(0,25,img.shape)

noisy = img + noise
noisy = np.clip(noisy,0,255)

plt.imshow(noisy,cmap='gray')
plt.title("Noisy Image")
plt.savefig("output/noisy.png")
plt.close()


median = cv2.medianBlur(noisy.astype(np.uint8),3)

plt.imshow(median,cmap='gray')
plt.title("Median Filtered Image")
plt.savefig("output/median_filtered.png")
plt.close()


# -------------------------
# 2iv) Unsharp masking
# -------------------------

blur = convolution(img,kernel3)

mask = img - blur

sharp = img + mask
sharp = np.clip(sharp,0,255)

plt.imshow(sharp,cmap='gray')
plt.title("Unsharp Masking")
plt.savefig("output/unsharp.png")
plt.close()


# ======================================================
# 3. Histogram Processing
# ======================================================


# Histogram original

plt.hist(img.ravel(),256,[0,256])
plt.title("Original Histogram")
plt.savefig("output/histogram_original.png")
plt.close()


# Histogram Equalization

equalized = cv2.equalizeHist(img)

plt.imshow(equalized,cmap='gray')
plt.title("Equalized Image")
plt.savefig("output/equalized_image.png")
plt.close()

plt.hist(equalized.ravel(),256,[0,256])
plt.title("Equalized Histogram")
plt.savefig("output/histogram_equalized.png")
plt.close()


# -------------------------
# 3ii) Contrast Stretching
# -------------------------

min_val = np.min(img)
max_val = np.max(img)

stretch = (img-min_val)*(255/(max_val-min_val))
stretch = np.clip(stretch,0,255)

plt.imshow(stretch,cmap='gray')
plt.title("Contrast Stretching")
plt.savefig("output/contrast_stretch.png")
plt.close()


print("Assignment completed. Check output folder.")