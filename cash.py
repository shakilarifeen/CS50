def main():
    while True:
        try:
            change = float(input("Change: "))
            if change > 0.0:
                break
        except ValueError:
                print("")

    if change > 0.24:
        count = count_quarters(change)
        remain = round((change % 0.25), 2)
        count = count + count_dimes(remain)
        remain = round((remain % 0.10), 2)
        count = count + count_nickels(remain)
        remain = round((remain % 0.05), 2)
        count = count + count_pennies(remain)
    elif change > 0.09 and change < 0.25:
        count = count_dimes(change)
        remain = round((change % 0.10), 2)
        count = count + count_nickels(remain)
        remain = round((remain % 0.05), 2)
        count = count + count_pennies(remain)
    elif change > 0.04 and change < 0.10:
        count = count_nickels(change)
        remain = round((change % 0.05), 2)
        count = count + count_pennies(remain)
    else:
        count = count_pennies(change)
    print(f"{int(count)}")


def count_quarters(n):
    count = n // 0.25
    return count

def count_dimes(n):
    count = n // 0.10
    return count

def count_nickels(n):
    count = n // 0.05
    return count

def count_pennies(n):
    count = n // 0.01
    return count

main()




