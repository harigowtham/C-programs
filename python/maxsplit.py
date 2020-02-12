s = 'Python is Nice'

#str_list = s.split(sep=' ')
#['Python', 'is', 'Nice']

#str_list = s.split(sep=' ', maxsplit=1)
#['Python', 'is Nice']

#str_list = s.split()
#['Python', 'is', 'Nice']

#str_list = s.rsplit(sep=' ')
#['Python', 'is', 'Nice']

str_list = s.rsplit(sep=' ', maxsplit=1)
#['Python is', 'Nice']

print(str_list)

#sep and maxsplit works only with python3
#sep refers to the delimiter
#maxsplit refers to the number number of items it has to be split into
# rsplits starts working from back to front(reverse)
