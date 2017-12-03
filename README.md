# OOP_Lab_Flowerpoot
<h5> Создайте иерархию классов, имитирующих информацию о жизни комнатных растений.

<h5> Создайте иерархию классов, имитирующих информацию о жизни комнатных растений:
 <h5>класc-комната (Room), состоящий из набора комнатных растений (указатели на объекты Houseplant);
 <h5>абстрактный класс, представляющий все комнатные растения (Houseplant), характеризующийся:
<li>
* названием;
* возрастом;
* периодом полива (целое число - количество дней между двумя поливами);
* датой последнего полива;
* чисто виртуальным методом для “осуществления” полива;
* чисто виртуальным методом, сообщающим растению, что прошел очередной день;
* производный класс, представляющий цветущее комнатное растение (FloweringHouseplant), расширяющий абстрактное комнатное растение:
* длительность цветения (количество дней);
* необходимое и текущее количество сделанных правильно поливов для начала цветения;
* реакция на “осуществление” полива и смену очередного дня:
** если полив сделан строго по графику (от даты последнего полива прошло ровное количество дней, предусмотренное периодом полива), текущее количество сделанных правильно поливов увеличивается:
** если полив сделан с задержкой или опережением графика на 1 день, он никак не засчитывается;
** если полив сделан с задержкой или опережением графика более чем на 1 день, число правильных поливов уменьшается на 1 (если уже не равно 0);
при достижении необходимого количества правильных поливов, растение начинает цвести:
при цветении растение нужно также поливать в соответствии с графиком;
если полив сделан строго по графику, либо с задержкой или опережением на 1 день - растение продолжает цвести;
если режим полива нарушается, растение перестает цвести, цикл полива начинается заново;
если цветение завершается успешно (проходит плановый период цветения), растение “крепчает”, и его период полива увеличивается на 2 дня, на консоли печатается поздравительное сообщение, и цикл полива начинается заново;
производный класс, представляющий плодоносящее комнатное растение (FruitingHouseplant), дополняющий цветущее комнатное растение:
название плода (например, “lemon” для растения “lemon tree”);
длительность плодоношения (количество дней);
плодоношение таких растений начинается сразу после успешного цветения;
в период плодоношения также нужно поливать растение в соответствии с графиком, правила аналогичны цветению;
успешное завершение плодоношения печатает на консоли поздравительное сообщение с упоминанием названия растения и созревшего на нем плода, далее цикл полива начинается заново;
производный класс, представляющий лиственное комнатное растение (FoliarHouseplant), расширяющий абстрактное комнатное растение:
высота растения (в сантиметрах);
реакция на “осуществление” полива и смену очередного дня:
если растение полито вовремя либо с опережением/задержкой на 1 день, растение вырастает на 1 см;
если график полива нарушается, растение не растет;
если высота растения достигает 250см, оно перестает “влазить” в квартиру, и его нужно рассадить - создать новое растение такого же типа (условно порежем существующее пополам).
важно: новое растение должно автоматически добавиться в комнату, однако запрещается делать прямую зависимость между данным классом и классом Room;
производный класс, представляющий искусственное комнатное растение (ArtificialHouseplant) расширяющий абстрактное комнатное растение::
такое растение ни растет, ни плодоносит, ни цветет;
при поливе выдает на консоль предупреждение о возможной ошибке.

Разработайте тестовую консольную программу, создающую объекты разработанной иерархии, и максимально полностью покрывающую все возможные описанные ситуации поведения растений. Должны быть созданы необходимые объекты, имитированы ситуации успешного и не успешного полива, и т.д. Корректно уничтожьте всех объекты. Желательно соблюдать структуру программы, предложенную в базовых вариантах.
