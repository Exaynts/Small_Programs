import math
def input_number():
    while True:
        try:
            num = int(input())
            return num
        except ValueError:
            print("Enter the number correctly!")

def input_list(q):
    query = []
    for i in range(q):
        print(f"list[{i}] = ", end = "")
        query.append(input_number())
    return query

def find_digit(k):
    # Пропускаем номера всех чисел, длиной ниже искомого и узнаём длину целевого числа
    pre_low = 0
    low = 0
    length = 0
    while low < k:
        length += 1
        pre_low = low
        low += length * 9 * (10 ** (length - 1))
    low = pre_low
    
    # Номер нужного подчисла в списке чисел с длиной length
    target_number = (k - low - 1) // length + (10 ** (length - 1))
    
    # Порядок цифры в нужном подчисле
    if (k - low) % length == 0:
        target_place = length
    else:
        target_place = (k - low) % length
    
    # Получение целевой цифры числа путём отбрасывания лишних цифр с конца
    while target_number >= (10 ** target_place):
        target_number //= 10  # Отбрасываем последнюю цифру
    
    digit = target_number % 10
    return digit
# Основные действия
def main():
    # Ввод числа q
    print("q = ", end="")
    q = input_number()
    
    # Ввод списка из q чисел
    query = input_list(q)
    
    # Определяем нужные цифры по запросам
    result = []
    for num in query:
        result.append(find_digit(num))
    
    # Вывод искомых цифр
    for digit in result:
        print(digit)
# Запуск программы
main()
