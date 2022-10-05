# Лабораторная работа по модели GitFlow

### Ниже представлены команды для работы с расширением Пit-flow

## Общее

git-flow — это набор расширений git предоставляющий высокоуровневые операции над репозиторием для поддержки модели ветвления Vincent Driessen. [подробнее](https://habr.com/ru/post/106912/)

### Инициализация

Перед началом работы с git-flow нужно проинициализируйте его внутри существующего git-репозитория:

```
git flow init 
```

## Работа с фичами 

Разработка новых фич для последующих релизов. Обычно присутствует только в репозиториях разработчиков.

### Создание фичи

Разработка новых фич начинается из ветки <kbd>develop</kbd>.

Для начала разработки фичи выполните:

``` bash
# [name] - название новой фичи
git flow feature start [name]
```

### Завершение фичи

При завершении фичи происходит следущее:

* Слияние и удаление ветки фичи в <kbd>develop</kbd>;
* Переключение обратно на ветку <kbd>develop</kbd>.

Окончание разработки фичи выполняется так:

``` bash
# [name] - название новой фичи
git flow feature finish [name]
```


### Публикация и получение фичи

Можно опубликовать фичу на удалённом сервере, чтобы её могли использовать другие пользователи. <kbd>*например, при совместной разработке с коллегами</kbd>

Также можно получить фичу, опубликованную другим пользователем.

``` bash
git flow feature publish [name]     # публикация фичи
git flow feature pull origin [name] # получение фичи
```

## Работа с релизами

Поддержка подготовки нового релиза продукта. Позволяет устранять мелкие баги и подготавливать различные метаданные для релиза.

### Создание релиза

Для начала работы над релизом используйте команду ```git flow release```. Она создаёт ветку релиза, ответляя от ветки <kbd>develop</kbd>.

``` bash
# [name] - название релиза
git flow release start [name] [base]
```

* При желании вы можете указать <kbd>[base]</kbd> - коммит в виде его хеша sha-1, чтобы начать релиз с него. Этот коммит должен принадлежать ветке <kbd>develop</kbd>.

### Завершение релиза

Завершение релиза — один из самых больших шагов в git-ветвлени. При этом происходит несколько действий:

* Ветка релиза сливается в ветку <kbd>main</kbd>
* Релиз помечается тегом равным его имени с комментарием
* Ветка релиза сливается обратно в ветку <kbd>develop</kbd>
* Ветка релиза удаляется


``` bash
git flow release finish [name] -m "[comment]" # завершение релиза
# [comment] - коментарий для тега по имени релиза
```
 
* Не забудьте отправить изменения в тегах с помощью команды ```git push --tags```

### Публикация и получение релиза
Это происхаодит аналогично, как и с фичами.

``` bash
git flow release publish [name]     # публикация релиза
git flow release pull origin [name] # получение релиза
```

* Желательно сразу публиковать ветку релиза после создания, чтобы позволить другим разработчиками выполнять коммиты в ветку релиза.

## Работа с исправлениями

Исправления нужны в том случае, когда нужно незамедлительно устранить нежелательное состояние продакшн-версии продукта. Может ответвляться от соответствующего тега на ветке <kbd>main</kbd>, который отмечает выпуск продакшн-версии

### Созадение исправлений

Ветка исправления отвлетвляется от ветки <kbd>main</kbd>.

Как и в случае с другими командами git flow, работа над исправлением начинается так:

``` bash
# [version] - название хотфикса
git flow hotfix start [version] [base]
```

* При желании можно указать <kbd>[base]</kbd> - коммит, от которого произойдёт ответвление.

### Завершение исправления

Завершение исправления происходит абсолютно аналогично релизам:

* Ветка исправления сливается в ветку <kbd>main</kbd>
* Исправление помечается тегом равным его имени с комментарием
* Ветка исправления сливается обратно в ветку <kbd>develop</kbd>
* Ветка исправления удаляется


``` bash
git flow hotfix finish [name] -m "[comment]" # завершение релиза
# [comment] - коментарий для тега по имени исправления
```
 
* Не забудьте отправить изменения в тегах с помощью команды ```git push --tags```

### Публикация и получение релиза

Аналогичны предыдущим командам

``` bash
git flow hotfix publish [name]     # публикация исправления
git flow hotfix pull origin [name] # получение исправления
```

## Работа с Vim

При открытии Vim (например, когда не указан комментарий для тега в командах завершения релиза/исправления) могут понадобиться следующие команды:

``` bash
# Ввод в командном режиме)

:q!             — выйти без сохранения)
:wq             — сохранить файл и выйти)
```
