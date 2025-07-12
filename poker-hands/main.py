from collections import Counter

CARD_ORDER = '23456789TJQKA'
CARD_VALUES = {r: i for i, r in enumerate(CARD_ORDER, 2)}

def hand_rank(hand):
    values = sorted([CARD_VALUES[c[0]] for c in hand], reverse=True)
    suits = [c[1] for c in hand]
    counts = Counter(values)
    count_values = sorted(((count, val) for val, count in counts.items()), reverse=True)
    is_flush = len(set(suits)) == 1
    is_straight = len(counts) == 5 and max(values) - min(values) == 4

    if is_straight and is_flush:
        return (8, max(values))
    elif count_values[0][0] == 4:
        return (7, count_values[0][1], count_values[1][1])
    elif count_values[0][0] == 3 and count_values[1][0] == 2:
        return (6, count_values[0][1], count_values[1][1])
    elif is_flush:
        return (5, values)
    elif is_straight:
        return (4, max(values))
    elif count_values[0][0] == 3:
        return (3, count_values[0][1], [v for v in values if v != count_values[0][1]])
    elif count_values[0][0] == 2 and count_values[1][0] == 2:
        return (2, sorted([count_values[0][1], count_values[1][1]], reverse=True), [v for v in values if v not in [count_values[0][1], count_values[1][1]]])
    elif count_values[0][0] == 2:
        return (1, count_values[0][1], [v for v in values if v != count_values[0][1]])
    else:
        return (0, values)

def player1_wins(hands):
    wins = 0
    for line in hands:
        h1 = line[:5]
        h2 = line[5:]
        if hand_rank(h1) > hand_rank(h2):
            wins += 1
    return wins
