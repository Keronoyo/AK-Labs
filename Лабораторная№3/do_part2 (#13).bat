@chcp 65001
@xcopy /s /y /i "Початкова папка для 2-ї частини" "Кінцева папка для 2-ї частини\Тут!"
@echo Копіювання вдалося. Error code: %ERRORLEVEL%
@rd /s /q "Початкова папка для 2-ї частини"
@echo Видалення старих файлів вдало завершено. Error code: %ERRORLEVEL%
@mkdir "Початкова папка для 2-ї частини"
@pause