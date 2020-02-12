list = [{'max': '', 'screenshot': u'zypper_up-1.png', 'failure_count': 0, 'unknown': '', 'list': '', 'pass': 1, 'fail': '', 'found': '', 'unknown_count': 0}, {'max': '', 'screenshot': u'zypper_up-2.png', 'failure_count': 0, 'unknown': '', 'list': '', 'pass': 1, 'fail': '', 'found': '', 'unknown_count': 0}, {'max': '', 'screenshot': u'zypper_up-3.png', 'failure_count': 0, 'unknown': '', 'list': '', 'pass': 1, 'fail': '', 'found': '', 'unknown_count': 0}, {'max': '', 'screenshot': u'zypper_up-22.png', 'failure_count': 0, 'unknown': '', 'list': '', 'pass': 1, 'fail': '', 'found': '', 'unknown_count': 0}, {'max': '', 'screenshot': u'zypper_up-22.png', 'failure_count': 0, 'unknown': '', 'list': '', 'pass': 1, 'fail': '', 'found': '', 'unknown_count': 0}]
#print list
for i in range(len(list)):
    #for screenshot in list[0][i]:
        #print screenshot
    print list[0].values()[1]
    list[0] = ['max': '', 'screenshot': u'zypper_up-2.png', 'failure_count': 0, 'unknown': '', 'list': '', 'pass': 1, 'fail': '', 'found': '', 'unknown_count': 0]
    print list[0].values()[1]

