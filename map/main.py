idade = {
    "Alice": 30,
    "Bob": 25
}

print("Idade de Alice:", idade["Alice"])

for nome, idade_valor in idade.items():
    print(f"{nome} tem {idade_valor} anos.")
