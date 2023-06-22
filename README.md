<h1> Программа для генерации объяснения выражения </h1>
<u>Автор:</u> <i>Янцев Михаил</i>
<br>
Программа позволяет генерировать «объяснение» выражения, дерево разбора которого содержит названия и типы данных переменных, функций и их аргументов, а также операции, производимые над операндами.
<h2><b> Формат входных данных</b></h3>
Входные данные представляются в виде одного текстового файла с расширением .xml.<br>
Поддерживаются операции в соответствии с синтаксисом языка Си.<br>
Операция определяется как атрибут тега «operation» - «operType».<br>
Операнд определяется как элемент тега «operand».<br>
Тип переменной или возвращаемого значения функции определяется как атрибут тега «operand» - «dataType».<br>
Название переменной или функции определяется как атрибут тега «operand» - «name».<br>
Аргумент функции определяется как атрибут тега «operand» - «argument».<br>
<h2><b> Формат выходных данных</b></h2>
Выходной файл - текстовый файл с расширением .txt. Он должен содержит одну строку: «объяснение» выражения.
<h2><b> Список поддерживаемых операций </b></h2>
 <table>
	<tr>
		<th>Название операции</th>
		<th>Формат записи</th>
	</tr>
	<tr>
		<td>Сумма</td>
		<td>+</td>
	</tr>
	<tr>
		<td>Разность</td>
		<td>-</td>
	</tr>
	<tr>
		<td>Произведение</td>
		<td>*</td>
	</tr>
	<tr>
		<td>Деление</td>
		<td>/</td>
	</tr>
	<tr>
		<td>Остаток от целочисленного деления</td>
		<td>%</td>
	</tr>
	<tr>
		<td>Инкремент</td>
		<td>++</td>
	</tr>
	<tr>
		<td>Декремент</td>
		<td>--</td>
	</tr>
	<tr>
		<td>Отрицание</td>
		<td>!</td>
	</tr>
	<tr>
		<td>Логическое умножение</td>
		<td>&&</td>
	</tr>
	<tr>
		<td>Логическое сложение</td>
		<td>||</td>
	</tr>
</table>
<h2><b> Пример работы программы </b></h2>
<center>Дерево разбора выражения</center>
<img src="doxygen/example.png">
<center>Xml формат</center>
<img src="doxygen/exmpl_xml.png">
<center>Объяснение выражения</center><br>
деление суммы целого числа строк x и целого числа столбцов y на разность вещественного среднего значения (x,y) от f и инкремента вещественного определителя z