<html>
<h2>1. Используем VS Code</h2>
<h2>2. Установка MSYS2 64 </h2>
<p> Переходим на сайт <a href="https://www.msys2.org/" target="_blank">www.msys2.org</a>
</p>
<p>Скачиваем установщик <a href="https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe" target="_blank"> msys2-x86_64-20241208.exe</a>
</p>
<p>Запускаем установщик и следуем инструкциям ниже на этой же странице с небольшими изменениями:
<ul>
<li>- ставим в папку c:\msys64\</li>

</ul>
</p>
<h2>3. Установка MinGW64 вместе с freeglut</h2>
<p>запускаем MSYS2 приложение через Пуск</p>
затем даем команды (копируем и вставляем, при вопросах жмем Y):
<p>pacman -Syu</p>
<p>pacman -S mingw-w64-x86_64-toolchain</p>
<p>pacman -S mingw-w64-x86_64-freeglut</p>
<p>Первая обновляет пакеты, а вторая необходима для компиляции, третья устанавливает freeglut</p>
<h2>Добавляем путь компилятора к переменным среды</h2>
<p>Пуск-Система-Дополнительные параметры системы-Переменные среды-Системные переменные-PATH <br>
Изменить-Создать "C:\msys64\mingw64\bin\"</p>
<p>Желательно перегрузить компьютер</p>
<p>Здесь был Максим</p>
<p>Изменено в VS Code</p>
<p>Ссылка на мою <a href="https://github.com/lazy-santa/Embedded-System-Labs" target="_blank"> лабу</a>
</html>
