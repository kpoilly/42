import sys
import cv2
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from load_image import ft_load

matplotlib.use('gtk3agg')


def ft_transpose(img):
    """
    transpose an image (rotate to 90deg)

    Args:
        img: Numpy array of the pixel content of
        the image in RGB format.

    Returns:
        Numpy array of the pixel content of
        the transposed image in RGB format.
    """
    
    height, width = img.shape
    img_transposed = np.zeros((height, width), dtype=img.dtype)

    for i in range(height):
        for j in range(width):
            img_transposed[j, i] = img[i, j]
    return img_transposed


def main():
    try:
        path = "animal.jpeg"
        img_array = ft_load(path)
        print(img_array)

        img_array = img_array[100:500, 450:850, 0]
        img_array = np.squeeze(img_array)
        # img_array = np.transpose(img_array)
        img_array = ft_transpose(img_array)
        print("New shape after transpose:", img_array.shape)
        print(img_array)

        img = cv2.cvtColor(img_array, cv2.COLOR_BGR2RGB)
        fig, ax = plt.subplots()
        ax.imshow(img)
        plt.show()

    except AssertionError as e:
        print("AssertionError:", e, file=sys.stderr)
    except ValueError as e:
        print("ValueError:", e, file=sys.stderr)
    except Exception as e:
        print("Error:", e, file=sys.stderr)


if __name__ == "__main__":
    main()
