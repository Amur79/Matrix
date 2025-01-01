## 1. Используем VS Code
## 2. Установка MSYS2 64
Переходим на сайт <a href="https://www.msys2.org/" target="_blank">www.msys2.org</a>

Скачиваем установщик <a href="https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe" target="_blank"> msys2-x86_64-20241208.exe</a>

Запускаем установщик и следуем инструкциям ниже на этой же странице с небольшими изменениями:

Cтавим в папку c:\msys64\

![image](https://github.com/user-attachments/assets/b4f326e3-213b-4d07-ab8b-55d9cc401882)

## 3. Установка MinGW64 вместе с freeglut</h2>
Запускаем MSYS2 приложение через Пуск
![image](https://github.com/user-attachments/assets/3e9ec6af-831e-40c4-b6aa-68eaf09693c9)

Примерно такой путь должен получится
![image](https://github.com/user-attachments/assets/46d81321-9c6f-474d-9e23-ba83590ab4be)

Затем даем команды (копируем и вставляем, при вопросах жмем Y):

pacman -Syu

![image](https://github.com/user-attachments/assets/cf5d68f8-9f7e-444e-ad5a-488d6da138be)

Нажимаем Y

![image](https://github.com/user-attachments/assets/e78a71fd-8374-4d89-94c9-acd2b7b4aa37)

Еще раз Y

![image](https://github.com/user-attachments/assets/7a5f29a4-c250-496c-8fc5-8e97129ba638)

Со следующими командами делаем теже шаги

pacman -S mingw-w64-x86_64-toolchain

![image](https://github.com/user-attachments/assets/821cfc53-9b1d-4c98-b542-c1e2657b9e44)

Жмем Enter

![image](https://github.com/user-attachments/assets/810fd2d5-6450-48ef-a6e4-905147bd8afd)

Потом Y

![image](https://github.com/user-attachments/assets/004bafb9-feb0-4775-82d1-cdafccd7570d)


pacman -S mingw-w64-x86_64-freeglut

![image](https://github.com/user-attachments/assets/b6a8d2d3-01fb-459e-98ed-f6760b1d7776)

Нажимаем Y

![image](https://github.com/user-attachments/assets/67bfedac-eb68-49c6-8a0b-98291025cf57)

Первая обновляет пакеты, а вторая необходима для компиляции, третья устанавливает freeglut

## Добавляем путь компилятора к переменным среды

Пуск-Система-Дополнительные параметры системы Переменные среды-Системные переменные-PATH

Изменить-Создать "C:\msys64\mingw64\bin\"

Нужно перегрузить компьютер

Здесь был Максим

Изменено в VS Code

Ссылка на мою <a href="https://github.com/lazy-santa/Embedded-System-Labs" target="_blank"> лабу</a>

