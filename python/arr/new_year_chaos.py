def minimumBribes(q):
    moves = 0
    for pos, val in enumerate(q):
        if (val-1) - pos > 2:
            return "Too chaotic"
        for j in xrange(max(0,val-2), pos):
            if q[j] > val:
                moves+=1
    return moves
