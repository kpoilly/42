def ft_filter(fun, iter):
    """
    Return an iterator yielding those items
    of iterable for which function(item) is true.

    Args:
        fun: function to apply on each item.
        iter: list to iter.
    """
    if fun:
        return (i for i in iter if fun(i))
    return (i for i in iter if i)
