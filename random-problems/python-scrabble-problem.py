#https://www.reddit.com/r/dailyprogrammer/comments/4oylbo/20160620_challenge_272_easy_whats_in_the_bag/

bag = {"A":9, "B":2, "C":2, "D":4, "E":12, "F":2, "G":3, "H":2, "I":9, "J":1, "K":1, "L":4, "M":2, "N":6, "O":8, "P":2, "Q":1, "R":6, "S":4, "T":6, "U":4, "V":2, "W":2, "X":1, "Y":2 , "Z":1, "_":2}

table1 = "PQAREIOURSTHGWIOAE_"
table2 = "LQTOONOEFFJZT"
table3 = "AXHDRUIOR_XHJZUQEE"


def solution(str,bag):
    countDict = {}
    lst_count = []
    for c in str:
        bag[c] = bag[c] - 1
        if bag[c] < 0:
            print ("Invalid input. More {0}'s have been taken from the bag than possible.".format(c))
            return
    for c in bag:
        if bag[c] in countDict:
            countDict[bag[c]].append(c)
        else:
            countDict[bag[c]] = [c]

    for key in countDict:
       countDict[key].sort()
       lst_count.append(-1*key)
    lst_count.sort()

    for index in range(0,len(lst_count)):
        print "{0}: ".format(abs(lst_count[index])) + ",".join(countDict[abs(lst_count[index])])

solution(table1,bag)
