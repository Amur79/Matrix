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

Затем даем команды (копируем и вставляем, при вопросах жмем Y):
pacman -Syu

pacman -S mingw-w64-x86_64-toolchain

pacman -S mingw-w64-x86_64-freeglut

Первая обновляет пакеты, а вторая необходима для компиляции, третья устанавливает freeglut

## Добавляем путь компилятора к переменным среды

Пуск-Система-Дополнительные параметры системы Переменные среды-Системные переменные-PATH

Изменить-Создать "C:\msys64\mingw64\bin\"

Нужно перегрузить компьютер

Здесь был Максим

Изменено в VS Code

Ссылка на мою <a href="https://github.com/lazy-santa/Embedded-System-Labs" target="_blank"> лабу</a>

