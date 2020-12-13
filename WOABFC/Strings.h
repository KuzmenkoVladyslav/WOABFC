#pragma once
#include <SFML\Graphics.hpp>

static int state;

static int getState()
{
	return state;
}

static void setState(int newState)
{
	state = newState;
}

static sf::String languageEnglish[24] = {
	"Tutorial",
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
	"Cavalry\nCan attack twice each turn.",
	"Anti-Cavalry\nDeal double damage to Cavalry\nsquads. If a Cavalry squad\nattacks an Anti-Cavalrywith its\nfirst hit of a turn, it loses\nthe ability to attack a second\ntime that turn.",
	"Anti-Cavalry Cavalry\nCan attack twice each turn.\nDeal double damage to Cavalry\nsquads. If a Cavalry squad\nattacks an Anti-Cavalrywith its\nfirst hit of a turn, it loses\nthe ability to attack a second\ntime that turn.",
	"Doesn't have uniqe ability.",
	""
};

static sf::String languageRussian[24] = {
	L"Обучение",
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
	L"Кавалерия\nМожет атаковать дважды\nза один ход.",
	L"Анти-Кавалерия\nНаносит двойной урон войскам\nКавалерии противника. Если\nКавалерийский отряд\nатаковал Анти-кавалерийский на\nсвоём первом ударе за ход,\nто он теряет возможность\nатаковать второй раз\nза этот ход.",
	L"Анти-Кавалерийская Кавалерия\nМожет атаковать дважды\nза один ход.\nНаносит двойной урон войскам\nКавалерии противника. Если\nКавалерийский отряд\nатаковал Анти-кавалерийский на\nсвоём первом ударе за ход,\nто он теряет возможность\nатаковать второй раз\nза этот ход.",
	L"Нет уникальных\nособенностей.",
	L""
};

static sf::String languageUkrainian[24] = {
	L"Навчання",
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
	L"Ближній бій\nОтримує половину шкоди від\nвійськДальнього бою.",
	L"Дальній бій\nІгнорує шкоду супротивника\nколи атакує. Не наносить шкоди\nу відповідь коли був атакований.",
	L"Кавалерія\nМоже атакувати двічі за один\nхід.",
	L"Анти-Кавалерія\nНаносить подвійну шкоду\nвійськам Кавалерії супротивника.\nЯкщо Кавалерійский загін атакував\nАнти-кавалерійский на своїй\nпершій атаці за хід, то він\nвтрачає можливість атакувати\nдругий раз за цей хід.",
	L"Анти-Кавалерійска Кавалерія\nМоже атакувати двічі за один\nхід. Наносить подвійну шкоду\nвійськам Кавалерії супротивника.\nЯкщо Кавалерійский загін атакував\nАнти-кавалерійский на своїй\nпершій атаці за хід, то він\nвтрачає можливість атакувати\nдругий раз за цей хід.",
	L"Немає унікальних здібностей.",
	L""
};

static sf::String languageString(int indexOfString)
{
	switch (state)
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