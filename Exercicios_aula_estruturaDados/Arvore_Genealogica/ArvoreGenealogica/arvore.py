tam_familia = int(input("Digite o tamanho da sua familia: "))

familia = {}
familia_ordem={}

for i in range (tam_familia):
    nome = str(input(f"digite o nome do {i+1}º integrante: "))
    idade = int(input("digite  idade dele: "))
    familia[f'{nome}'] = idade

for i in sorted(familia, key = familia.get):
    familia_ordem[f'{i}'] = familia[i]
    
print(familia_ordem)

lista_familia = list(familia_ordem.items())

for i in range(len(lista_familia)):
    nome_now, idade_now = lista_familia[i]

    for j in range(len(lista_familia)):
        if i != j:
            nome_next, idade_next = lista_familia[j]


    
    
