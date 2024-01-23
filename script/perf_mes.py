import time

def perf_mes(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        func(*args, **kwargs)
        end = time.time()
        print("Time of execution: {} sec".format(end - start))
    return wrapper

