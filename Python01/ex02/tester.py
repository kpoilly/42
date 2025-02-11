from load_image import ft_load


try:
    print(ft_load("landscape.jpg"))
    print(ft_load("xavierniel.png"))
except ValueError as e:
    print("ValueError:", e)
except AssertionError as e:
    print("AssertionError:", e)