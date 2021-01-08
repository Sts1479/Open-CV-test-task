# Open-CV-test-task

Программа для обработки изображений.

Загрузка 
load, ld
<name> - имя изображения, по имени оно доступно в других командах
<filename> - имя файла для загрузки the image в формате JPG

Сохранение изображения в формате jpg
store, s <name> <filename>
<name> - имя изображения 
<filename> - имя файла для сохранения

Сглаживание изображения
blur <from_name> <to_name> <size>
<from_name> - имя изображения
<to_name> - имя изображения
<size> - размер сглаживаемой области

Изменение размера изображения
resize <from_name> <to_name> <new_width> <new_height>
<from_name> - имя изображения
<to_name> - имя изображения
<new_width>
<new_height>

Выводит справку о поддерживаемых командах
help, h

Выход
exit, quit, q

пример сессии
ld img1 image.jpg
blur img1 img1b 5
s img1b image2.jpg
q

