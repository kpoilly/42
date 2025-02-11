import numpy as np


def slice_me(family: list, start: int, end: int) -> list:
    """
    Print the shape of a 2D array and truncate it.

    Args:
        family: 2D Numpy array or list of numbers (int or floats).
        start: beginning of the truncated array (int or float).
        end: end of the truncated array (int or float)

    Returns:
        Numpy array of a truncated version of family,
        based on the provided start and end arguments.
    """

    if not isinstance(family, (list, np.ndarray)):
        raise TypeError("family should be list or numpy arrays.")
    
    if not isinstance(start, int) or not isinstance(end, int):
        raise TypeError("start and end should be ints.")

    family = np.array(family)

    if not np.issubdtype(family.dtype, np.number):
        raise TypeError("list should only contain ints or floats.")

    print("My shape is :", family.shape)
    family = family[start:end]
    print("My new shape is :", family.shape)
    return family
