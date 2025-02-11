def ft_filter(fun, iter):
    if fun:
        return (i for i in iter if fun(i))
    return (i for i in iter if i)
