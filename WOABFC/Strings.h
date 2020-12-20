#pragma once
#include <SFML\Graphics.hpp>

static int languageState;

static int getLanguageState()
{
	return languageState;
}

static void setLanguageState(int newLanguageState)
{
	languageState = newLanguageState;
}

static sf::String languageEnglish[35] = {
	"HotSeat",
	"Multiplayer",
	"Settings",
	"How to play",
	"Exit",
	"Era: ",
	"Name: ",
	"Type: ",
	"Ancient",
	"Classic",
	"Medival",
	"Renaissancee",
	"Industrial",
	"Modern",
	"Atomic",
	"Information",
	"Future",
	"Meele\nTake half damage from Ranged\nsquads.",
	"Range\nIgnore enemy damage when\nthe attack. Can't damage\nenemy when was attacked.",
	"Cavalry\nCan attack infinite times.",
	"Anti-Cavalry\nDeal double damage to Cavalry\nsquads. If a Cavalry squad\nattacks an Anti-Cavalry it loses\nthe ability to attack a second\ntime that turn.",
	"Anti-Cavalry Cavalry\nCan attack infinite times.\nDeal double damage to Cavalry\nsquads. If a Cavalry squad\nattacks an Anti-Cavalry it loses\nthe ability to attack a second\ntime that turn.",
	"Doesn't have uniqe ability.",
	"Cost: ",
	" points of the turn.",
	"You are running out of space or points for the turn.",
	"- the number of hit points at the player's castle.",
	"- current / maximum number of action points a player has.",
	"- update the squad list in the store.",
	"- upgrade to the next era.",
	"- increase the number of cells for the active army by 1.",
	"- go to battle.",
	"- demobilize the squad. If your current action points\n  are less than the maximum, then you will receive 1 additional\n  action point for this turn.",
	"- when you click on a squad in the store - you will spend\n1 action point and replenish your reserve.\n- when clicking on a squad in reserve - you put it in an active army.\n- when you click on a squad in the active army, you will place it in the reserve.",
	"- when holding down on a squad, move the cursor to another unit\n  and you will swap them."
};

static sf::String languageRussian[35] = {
	L"HotSeat",
	L"Многопользовательская игра",
	L"Настройки",
	L"Как играть",
	L"Выход",
	L"Эпоха: ",
	L"Название: ",
	L"Тип: ",
	L"Древний мир",
	L"Классическая эра",
	L"Средневековье",
	L"Эпоха Возрождения",
	L"Индустриальная эра",
	L"Новое время",
	L"Эпоха атома",
	L"Информационная эра",
	L"Будущее",
	L"Ближний бой\nПолучает половину урона от\nвойск Дальнего боя.",
	L"Дальний бой\nИгнорирует урон противника\nкогда атакует.\nНе наносит урон в ответ\nкогда был атакован.",
	L"Кавалерия\nМожет атаковать пока не умрёт.",
	L"Анти-Кавалерия\nНаносит двойной урон войскам\nКавалерии противника. Если\nКавалерийский отряд\nатаковал Анти-кавалерийский,\nто он теряет возможность\nатаковать в этот ход.",
	L"Анти-Кавалерийская Кавалерия\nМожет атаковать пока не умрёт.\nНаносит двойной урон войскам\nКавалерии противника. Если\nКавалерийский отряд\nатаковал Анти-кавалерийский,\nто он теряет возможность\nатаковать в этот ход.",
	L"Нет уникальных\nособенностей.",
	L"Стоимость: ",
	L" баллов действий.",
	L"У Вас не хватает места или баллов действий!",
	L"- количество очков жизни у замка игрока.",
	L"- текущее / максимальное количество баллов действий у игрока.",
	L"- обновить список отрядов в магазине.",
	L"- перейти в следующую эпоху.",
	L"- увеличить количество ячеек для активной армии на 1.",
	L"- перейти к бою.",
	L"- демобилизируйте отряд. Если количество ваших текущих\n  баллов действия меньше максимума, то получите 1 дополнительный\n  балл действий на этот ход.",
	L"- при нажатии на отряде в магазине - вы потратите 1 балл действий\n  и пополните свой резерв.\n- при нажатии на отряд в резерве - вы поместите его в активную армию.\n- при нажатии на отряд в активной армии - вы поместите его в резерв.",
	L"- при зажатии на отряде перенесите курсор на другой отряд\n  и вы поменяете их местами."
};

static sf::String languageUkrainian[35] = {
	L"HotSeat",
	L"Багато користувальницька гра",
	L"Налаштування",
	L"Як грати",
	L"Вийти",
	L"Епоха: ",
	L"Назва: ",
	L"Тип: ",
	L"Стародавній світ",
	L"Класична ера",
	L"Середньовіччя",
	L"Епоха Відродження",
	L"Індустріальна ера",
	L"Новий час",
	L"Епоха атому",
	L"Інформаційна ера",
	L"Майбутнє",
	L"Ближній бій\nОтримує половину шкоди від\nвійськ Дальнього бою.",
	L"Дальній бій\nІгнорує шкоду супротивника\nколи атакує. Не наносить шкоди\nу відповідь коли був атакований.",
	L"Кавалерія\nМоже атакувати доки не помре.",
	L"Анти-Кавалерия\nНаносить подвійну шкоду війскам\nКавалерії супротивника. Якщо\nКавалерійский загін атакував\nАнти-кавалерійский, то він втрачає\nможливість атакувати у цей хід.",
	L"Анти-Кавалерийская Кавалерия\nМоже атакувати доки не помре.\nНаносить подвійну шкоду війскам\nКавалерії супротивника. Якщо\nКавалерійский загін атакував\nАнти-кавалерійский, то він втрачає\nможливість атакувати у цей хід.",
	L"Немає унікальних здібностей.",
	L"Вартість: ",
	L" балів дій.",
	L"У Вас недостатньо місця або балів дій!",
	L"- теперішня кількість балів життя у замку гравця.",
	L"- теперішня / максимальна кількість балів дій у гравця.",
	L"- оновити список загонів у магазині.",
	L"- перейти у наступну епоху.",
	L"- збільшити кількість комірок для активної армії на 1.",
	L"- перейти до бою.",
	L"- демобілізйте загін. Якщо кількість ваших теперішніх балів дій\n  менше максимуму, то отримайте 1 додатковий бал дій на цей хід.",
	L"- при натисканні на загоні у магазині - ви витратите 1 бал дій\n  і поповните свій резерв.\n- при натисканні на загін у резерві - ви помістите його у активну армію.\n- при натисканні на загін у активній армії - ви помістите його до резерву.",
	L"- при натисканні на загоні перемістіть курсор на інший загін\n  і ви поміняєте їх місцями."
};

static sf::String languageString(int indexOfString)
{
	switch (languageState)
	{
	case 0:
		return languageEnglish[indexOfString];
		break;
	case 1:
		return languageRussian[indexOfString];
		break;
	case 2:
		return languageUkrainian[indexOfString];
		break;
	default:
		return "";
		break;
	}
}