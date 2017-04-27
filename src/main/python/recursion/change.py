def recMC(coin_value, change):
    min_coins = change
    if change in coin_value:
        return 1
    else:
        for i in [c for c in coin_value if c <= change]:
            num_coins = 1+recMC(coin_value, change-i)
            if num_coins < min_coins:
                min_coins = num_coins
    return min_coins

#print(recMC([1,5,10,20], 63))

def recDC(coin_value, change, known_results):
    min_coins = change
    if change in coin_value:
        known_results[change]=1
        return 1
    elif known_results[change] > 0:
        return known_results[change]
    else:
        for i in [c for c in coin_value if c <= change]:
            num_coins = recDC(coin_value, change-i, known_results) + 1
            if num_coins < min_coins:
                min_coins = num_coins
                known_results[change] = min_coins
    return min_coins

print(recDC([1,5,10,20], 63, [0]*64))
