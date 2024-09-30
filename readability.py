def main():
    text = input("Text: ")
    count_1 = count_letters(text)
    count_2 = count_words(text)
    count_3 = count_sentences(text)
    index = compute(count_1, count_2, count_3)
    if index < 1:
        print("Before Grade 1")
    elif index >= 1 and index <= 16:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


def count_letters(text):
    count = 0
    for i in text:
        if i.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for i in text:
        if i.isspace():
            count += 1
    return count


def count_sentences(text):
    count = 0
    for i in text:
        if i in ['.', '!', '?']:
            count += 1
    return count

def compute(x, y, z):
    avg_let = (x/y)*100
    avg_sen = (z/y)*100
    index = round((0.0588*avg_let) - (0.296*avg_sen) - 15.8)
    return index

main()
