import os
import tempfile

try:
    try:
        tmp_fd, tmp_filename = tempfile.mkstemp(dir="/tmp")
        s = "GeeksForGeeks: A Computer science portal for Geeks."
        line = str.encode(s)
        os.write(tmp_fd, line)
    finally:
        os.close(tmp_fd)
except Exception as e:
    print ("exception raised")
    raise Exception("Modify flows erri")
print ("exception not raised")
