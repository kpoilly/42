import time
import datetime

date = time.time()
print("Seconds since January 1, 1970: ", date, " or ", '{:.2e}'.format(date), " in scientific notation\n", datetime.datetime.fromtimestamp(time.time()).strftime('%b %d %Y'))