def word_split(words):
    words_in_second_param = words[1].split(",")
    output = []
    for i in range(len(words[0])-1):
        if words[0][:i+1] in words_in_second_param and words[0][i+1:] in words_in_second_param:
            output.append(words[0][:i+1])
            output.append(words[0][i+1:])
    if output == []:
        return "Bulunamadi"
    return output

    #   Alternative Solution
    # word = list(words[0])
    # words_in_second_param = words[1].split(",")
    # for i in range(1,len(word)):
    #     temp = word[:]
    #     temp.insert(i," ")
    #     x , y = "".join(temp).split()
    #     if x in words_in_second_param and y in words_in_second_param:
    #         return x + " , " + y
    # return "Bulunamadi"

print(word_split(["deeplearning","d,dll,a,deep,dee,base,lear,learning"]))