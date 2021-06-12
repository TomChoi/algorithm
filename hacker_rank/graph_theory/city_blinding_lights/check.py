with open("ref.txt","r") as rf:
    with open("out.txt","r") as of:
        refs=rf.readlines()
        outs=of.readlines()
        check=True
        for i in range(len(refs)):
            if refs[i] != outs[i]:
                print("index %d, ref: %s, out: %s" % (i+1, int(refs[i]), int(outs[i])))
                check=False
                break;
        if check:
            print("Work well!")
