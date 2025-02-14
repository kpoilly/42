import numpy as np
import cv2


def ft_load(path: str) -> np.array:
    """
    Loads an image, prints its format, and its pixels
    content in RGB format.

    Args:
        path: path to an image in JPG or JPEG format.

    Returns:
        Numpy array of the pixel content of the given image
        in RGB format.
    """

    if ".jpg" not in path.lower() and ".jpeg" not in path.lower():
        raise ValueError("Image should only be in .jpg or .jpeg format")

    img = cv2.imread(path)
    if img is None:
        raise AssertionError("Image could not be loaded. (is path correct ?)")

    img_array = np.array(img)

    print("The shape of image is:", img_array.shape)
    return img_array
