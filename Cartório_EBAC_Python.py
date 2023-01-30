#Cartório da EBAC em Python

import os

def cadastro():
    print("Você escolheu o cadastro de nomes!\n\n")
    cpf = input("Digite o CPF para cadastro:\n")
    filename = cpf

    fh = open(filename, 'x')
    fh.write(cpf)
    fh.write(",")
    fh.close()

    nome = input("Digite o nome para cadastro:\n")
    fh = open(filename, 'a')
    fh.write(nome)
    fh.write(",")
    fh.close()

    sobrenome = input("Digite o sobrenome para cadastro:\n")
    fh = open(filename, 'a')
    fh.write(sobrenome)
    fh.write(",")
    fh.close()

    cargo = input("Digite o cargo para cadastro:\n")
    fh = open(filename, 'a')
    fh.write(cargo)
    fh.write(",")
    fh.close()

    print("O cadastro foi finalizado!\n\n")
    os.system("PAUSE")
    menu()

def consulta():
    print("Você escolheu a consulta de nomes!\n\n")
    cpf = input("Digite o CPF de quem você deseja consultar: ")
    filename = cpf

    if os.path.exists(filename):
        fh = open(filename, 'r')
        for x in fh:
            print(x)
    else:
        print("Não foi possível abrir o arquivo, pois não foi localizado.\n")

    os.system("PAUSE")
    menu()

def deletar():
    print("Você escolheu deletar um nome!\n\n")
    cpf = input("Digite o CPF do usuário a ser deletado: ")
    filename = cpf

    if os.path.exists(filename):
        os.remove(filename)
        print("O usuário foi deletado com sucesso!\n\n")
        os.system("PAUSE")
        menu()
    else:
        print("O usuário deste CPF não se encontra no sistema!\n\n")
        os.system("PAUSE")
        menu()    

def menu():
    print('''
            ### Cartório da EBAC (Menu principal) ###\n
            Escolha a opção desejada:\n
            \t1 - Cadastrar nome
            \t2 - Consultar nome
            \t3 - Deletar nome
            \t4 - Sair do sistema
    ''')

    escolhido = str(input("Opção: "))

    if escolhido == '1':
        cadastro()
    elif escolhido == '2':
        consulta()
    elif escolhido == '3':
        deletar()
    elif escolhido == '4':
        print("Obrigado por utilizar o sistema!\n")
        quit()
    else:
        print("Você escolheu uma opção inválida\n\n")
        os.system("PAUSE")

menu()