import sys
import cv2
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from load_image import ft_load

matplotlib.use('gtk3agg')


def main():
    try:
        path = "animal.jpeg"
        img_array = ft_load(path)
        print(img_array)

        img_array = img_array[100:500, 400:800, 0]
        img_array = np.squeeze(img_array)
        print("New shape after slicing:", img_array.shape)
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
