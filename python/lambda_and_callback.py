def add(numbers, callback=lambda x: True):
    results = []
    for i in numbers:
        results.append(i) #results.append(add2(i))
        callback(numbers)
        #print results
    return results

def add2(number):
    return number + 2

print add([1,2,3,4]) #=> [3, 4, 5, 6]
