import os
import sys
import json
import pprint
from collections import OrderedDict

ss_list = []
text_list = []
dirx = sys.argv[1]
global is_needle_present
is_needle_present = 0;

def print_needle (ss_list, needle_not_found):
    for j in range(len(ss_list)):
        print "screenshot:%s |" % ss_list[j].values()[0],
        print "found:%s |" % ss_list[j].values()[4],
        print "pass:%s |" % ss_list[j].values()[2],
        print "fail:%s |" % ss_list[j].values()[3],
        print "unknown:%s |" % ss_list[j].values()[1],
        print "max number of needles:%s" % ss_list[j].values()[5],
        print ""
    print "needle_not_found : %s" % needle_not_found
    return

def needle (json_data, ss_list):
    needle_not_found = 0
    global is_needle_present
    for i in range(len(json_data)):
        dict = {'screenshot':'', 'found':'0', 'pass':'0', 'fail':'0', 'unknown':'0', 'max_number_of_needles':'0'}
        pass_count = 0;
        unknown_count = 0
        failure_count = 0
        found_count = 1
        screenshot_count = 0
        if 'needle' in json_data[i]:
            if 'screenshot' in json_data[i]:
                screenshot = json_data[i]['screenshot']
                for j in range(len(ss_list)):
                    temp_ss = ss_list[j].values()[0]
                    if temp_ss == screenshot:
                        pass_count = ss_list[j].values()[2]
                        unknown_count = ss_list[j].values()[1]
                        found_count = ss_list[j].values()[4]
                        failure_count = ss_list[j].values()[3]
                        screenshot_count += 1
                        found_count +=1
                screenshot_count += 1
                is_needle_present += 1
                if 'result' in json_data[i]:
                    result = json_data[i]['result']
                    if result == 'ok':
                        pass_count +=1
                    elif result == 'unk':
                        unknown_count +=1
                    elif result == 'fail':
                        failure_count +=1
                dict['screenshot'] = screenshot
                dict['found'] = found_count
                dict['pass'] = pass_count
                dict['fail'] = failure_count
                dict['unknown'] = unknown_count
                dict['max_number_of_needles'] = is_needle_present
                ss_list.append(dict)
        else:
            needle_not_found += 1

    return needle_not_found


def print_text (text_list, text_not_found):
    for j in range(len(text_list)):
        print "text:%s |" % text_list[j].values()[1],
        print "found:%s |" % text_list[j].values()[4],
        print "pass:%s |" % text_list[j].values()[2],
        print "fail:%s |" % text_list[j].values()[0],
        print "unknown:%s " % text_list[j].values()[3],
        print ""
    print "Text not found: %s" % text_not_found
    return

def text (json_data, text_list):
    text_not_found = 0
    for i in range(len(json_data)):
        dict = {'text':'', 'found':'0', 'pass':'0', 'fail':'0', 'unknown':'0'}
        pass_count = 0;
        unknown_count = 0
        failure_count = 0
        found_count = 1
        text_count = 0
        #print json_data
        if 'text' in json_data[i]:
            text = json_data[i]['text']
            for j in range(len(text_list)):
                temp_text = text_list[j].values()[1]
                if temp_text == text:
                    pass_count = text_list[j].values()[2]
                    unknown_count = text_list[j].values()[3]
                    found_count = text_list[j].values()[4]
                    failure_count = text_list[j].values()[0]
                    text_count += 1
                    found_count +=1
            text_count += 1
            if 'result' in json_data[i]:
                result = json_data[i]['result']
                if result == 'ok':
                    pass_count +=1
                elif result == 'unk':
                    unknown_count +=1
                elif result == 'fail':
                    failure_count +=1
            dict['text'] = text
            dict['found'] = found_count
            dict['pass'] = pass_count
            dict['fail'] = failure_count
            dict['unknown'] = unknown_count
            text_list.append(dict)
        else:
            text_not_found += 1
    return text_not_found

for files in os.listdir(dirx):
    if files.endswith(".json"):
        try:
            json_file = open(os.path.join(dirx, files))
            json_str = json_file.read()
            json_data = json.loads(json_str)
            needle_not_found = needle (json_data, ss_list)
            text_not_found = text (json_data, text_list)
        except ValueError as e:
            print('Invalid json: %s' % e)
            exit(1)
print "TEXT"
print_text (text_list, text_not_found)
print "NEEDLE"
print_needle (ss_list, needle_not_found)
