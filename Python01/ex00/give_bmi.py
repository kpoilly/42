import numpy as np


def give_bmi(height: list[int | float], weight: list[int | float]) -> list[int | float]:
    """
    Calcule l'IMC pour des listes de tailles et de poids.

    Args:
        height: Liste ou tableau NumPy de tailles (m).
        weight: Liste ou tableau NumPy de poids (kg).

    Returns:
        Tableau NumPy des valeurs d'IMC.
    """

    if not isinstance(height, (list, np.ndarray)) or not isinstance(weight, (list, np.ndarray)):
        raise TypeError("height and weight should be list or numpy arrays.")

    height = np.array(height)
    weight = np.array(weight)

    if height.size != weight.size:
        raise ValueError("lists should be the same size.")

    if not np.issubdtype(height.dtype, np.number) or not np.issubdtype(weight.dtype, np.number) or np.any(height <= 0) or np.any(weight <= 0):
        raise TypeError("lists should only contains positive ints or floats.")

    return weight / (height**2)


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """
    Vérifie si les valeurs d'une liste sont supérieures à une limite donnée.

    Args:
        values: Liste ou tableau NumPy de nombres.
        limit: Nombre représentant la limite.

    Returns:
        Tableau NumPy de booléens (True si supérieur à la limite, False sinon).
    """

    if not isinstance(bmi, (list, np.ndarray)):
        raise TypeError("values should be list or numpy array.")
    if not isinstance(limit, (int, float)):
        raise TypeError("limit should be int or float.")

    bmi = np.array(bmi)

    if not np.issubdtype(bmi.dtype, np.number):
        raise TypeError("values should only be numbers.")

    return (bmi > limit)
