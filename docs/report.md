<div style="display: flex; justify-content: space-between;">
    <div>Ответ на вопрос по выбору по теме "CMake подключение пакетов (FetchContent)"</div>
    <div>
        <div>Выполнил:</div>
        <div>студент 2 курса,</div>
        <div>гр. БПМ-22-4 Акперов Э.Б.</div>
        <div>25.12.2023</div>
    </div>
</div>

# CMake FetchContent()

Модуль FetchContent в CMake - это мощный инструмент для управления зависимостями в проекте. Он позволяет загружать контент из различных источников, например из системы контроля версий (Git, SVN и т.п.) во время настройки, а затем использовать их в  системе сборки.

## Как работает FetchContent

FetchContent работает в двух основных шагах:

1. **Объявление контента для загрузки**: Это делается с помощью функции `FetchContent_Declare()`. Эта функция принимает те же опции, что и команда `ExternalProject_Add()` в шагах загрузки и обновления/патчинга. Например, чтобы загрузить код из репозитория Git, необходимо установить опции `GIT_REPOSITORY` и `GIT_TAG`.

```cmake
FetchContent_Declare(
 googletest
 GIT_REPOSITORY https://github.com/google/googletest.git
 GIT_TAG      703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
```

2. **Заполнение контента**: После объявления контента для загрузки, нужно заполнить его с помощью функции `FetchContent_MakeAvailable()`. Эта функция добавляет цели, объявленные во внешнем контенте, в систему сборки. Можно использовать эти цели так же, как и при получении их через вызов `find_package()`.

```cmake
FetchContent_MakeAvailable(googletest)
```

## Расширенное использование

FetchContent также поддерживает более продвинутое использование:

- **Загрузка контента без добавления его в сборку**: Иногда нужно загрузить контент и сделать его доступным в предсказуемом месте, но не добавлять его в сборку. Это можно сделать, не вызывая `FetchContent_MakeAvailable()`.

```cmake
FetchContent_Declare(
 mycom_toolchains
 URL https://intranet.mycompany.com//toolchains_1.3.2.tar.gz
)
```

- **Загрузка контента в режиме скрипта CMake**: Можно также загрузить контент в режиме скрипта CMake с помощью функции `FetchContent_Populate()`. Эта функция указывает все детали контента, а распакованный контент будет размещен в указанной директории . Также она вызывается внутри функции `FetchContent_MakeAvailable()` (рекомендуется использование именно этой функции).

```cmake
FetchContent_Populate(
 firmware
 URL      https://mycompany.com/assets/firmware-1.23-arm.tar.gz
 URL_HASH MD5=68247684da89b608d466253762b0ff11
 SOURCE_DIR firmware
)
```

- **Загрузка контента из пакета**: Также можно загрузить контент из пакета. Например, чтобы загрузить библиотеку `lexy`, можно использовать следующие команды:

```cmake
FetchContent_Declare(lexy URL https://lexy.foonathan.net/download/lexy-src.zip)
FetchContent_MakeAvailable(lexy)
```


- **Свойства контента**: FetchContent_GetProperties - это функция CMake, которая позволяет получить свойства контента, объявленного с помощью FetchContent_Declare. Это может быть полезно, если вам нужно получить информацию о контенте, например, чтобы проверить, был ли контент уже загружен, или для получения значений свойств контента.

Пример использования FetchContent_GetProperties:

```cmake
FetchContent_Declare(
    my_library
    GIT_REPOSITORY https://github.com/username/my_library.git
    GIT_TAG v1.2.3
)

FetchContent_GetProperties(my_library)
if(NOT my_library_POPULATED)
    message(STATUS "my_library not found. Fetching...")
    FetchContent_Populate(my_library)
endif()
```
В этом примере мы объявляем контент my_library для загрузки из репозитория Git. Затем мы используем FetchContent_GetProperties для получения свойств этого контента. Мы проверяем, был ли контент уже загружен, и если нет, то используем FetchContent_Populate для его загрузки.

FetchContent_GetProperties возвращает следующие свойства контента:

- my_library_SOURCE_DIR: Путь к каталогу, в который был загружен контент.
- my_library_BINARY_DIR: Путь к каталогу сборки для контента.
- my_library_POPULATED: Булевое значение, указывающее, был ли контент уже загружен.


## Заключение

FetchContent - это удобный способ управления зависимостями в CMake. Он позволяет загружать контент из различных источников во время настройки и использовать его в вашей системе сборки. Это может значительно упростить ваш процесс сборки и сделать проект более удобным для использования.

## Источник

```markdown
[Официальная документация CMake](https://cmake.org/cmake/help/latest/module/FetchContent.html)
```
