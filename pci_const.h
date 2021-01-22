typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

//опция для записи в файл
#define FILE_OUTPUT_OPTION "--file"
enum Error {E_INVALID_OPTION = 1, E_NO_ROOT_PRIVELEGES};

//Стандарт PCI определяет для каждого устройства конфигурационное пространство размером до 256 регистров (8-битных),
//не приписанных ни к пространству памяти, ни к пространству ввода-вывода.
#define BUS_QUANTITY 256
//При этом,  к шине может быть подключено 32 различных устройства.
//По заданию надо проверить наличие всех 32, так что это константа
#define DEVICE_QUANTITY 32
//Одно устройство может выполнять до 8 различных функций.
#define FUNCTION_QUANTITY 8
//--На вопрос, почему функция?--
//С точки зрения конфигурирования устройств, минимальной адресуемой единицей является функция
//ее полный адрес состоит из трех частей: номера шины, номера устройства и номера функции.
//------------------------------

//Для чтения/записи регистров конфигурации любого устройства подключённого к шине PCI выделены два порта
#define CONTROL_PORT 0x0CF8 //Порт управления
#define DATA_PORT 0x0CFC //Порт данных

//Далее идут константы для границы просмотра
//Т.е. для того что бы просмотреть одну инфу, надо:
//1. Сдвинуть указатель на столько такой то бит от 2 байт (Старт считывания)
//2. Считать столько то бит, сколько говорит сдвиг
//Таким образом и происходит считывание

//Основные сдвиги
#define BUS_SHIFT 16
#define DEVICE_SHIFT 11
#define FUNCTION_SHIFT 8
#define REGISTER_SHIFT 2

//Портовые сдвиги
#define DEVICEID_SHIFT 16 //Device ID - уникальный идентификатор устройства. Назначается произво­дителем устройства. Запрещённое значение OxFFFF.
#define HEADER_TYPE_SHIFT 16 //Заголовок конфигурационного пространства мостов PCI
#define CLASS_CODE_SHIFT 8 //Class code - код класса устройства - определяет к какому классу относится устройство. Значение этого регистра следует декодировать и вывести класс уст­ройства в виде текстовой строки.
#define BASE_CLASS_SHIFT 8 //Base class - базовый класс(старший байт byte),
#define SUBCLASS_SHIFT 16 //Subclass - подкласс (средний байт)
#define INTERRUPT_PIN_SHIFT 8 // specific register level programming interface - специальный регистровый программный интерфейс (младший байт).
#define PRIMARY_BUS_NUMBER_SHIFT 0 //Номер первичной шины (это и номер моста)
#define SECONDARY_BUS_NUMBER_SHIFT 8 //Номер вторичной шины
#define SUBORDINATE_BUS_NUMBER_SHIFT 16 //Максимальный номер подчиненной шины
#define IO_LIMIT_SHIFT 8 //регистры, задающие начальный и конечный адрес пространства ввода-вывода устройств, расположенных за мостом.
#define MEMORY_LIMIT_SHIFT 16 //регистры, задающие начальный и конечный адрес пространства памяти, на которую отображены регистры ввода-вывода устройств, расположенных за мостом.
#define EXPANSION_ROM_BASE_ADDRESS_SHIFT 11 //Регистр Expansion ROM Base Address, как и для обычного устройства, задает положение ПЗУ расширения BIOS (если это ПЗУ присутствует в мосте).
#define TYPE_BITS_SHIFT 1 //Тип 
#define MEMORY_SPACE_BAR_ADDRESS_SHIFT 4
#define IO_MEMORY_SPACE_BAR_ADDRESS_SHIFT 2

//Старт считывания 
#define ID_REGISTER 0
#define CLASS_CODE_REGISTER 2
#define CACHE_LINE_SIZE_REGISTER 3
#define HEADER_TYPE_REGISTER 3
#define FIRST_BAR_REGISTER 4
#define BUS_NUMBER_REGISTER 6
#define IO_DATA_REGISTER 7
#define MEMORY_DATA_REGISTER 8
#define EXPANSION_ROM_BASE_ADDRESS_REGISTER 14 
#define INTERRUPT_PIN_REGISTER 15 
#define INTERRUPT_LINE_REGISTER 15
/*
Регистры Interrupt Line и Interrupt Pin относятся к прерываниям, вырабаты­ваемым мостом (если таковые имеются).
К линиям прерывания, транслируемым мостом, эти регистры отношения не имеют.
*/ 

#define INTERRUPT_LINES_NUMBER 16
/*
Interrupt Line  (RW) хранит номер входа контроллера прерывания для используемой линии запроса (0—15 — IRQ0-IRQ15 )
который выделяется устройству системой в результате работы алгоритма plug-and-play.
*/
#define BAR_QUANTITY 6
/*
Base address registers (BARs). Регистры базового адреса.
Конфигурационное пространство устройство может включать до шести регистров базового адреса.
BARы используются для решения двух задач.
Во первых они имеют доступные только для чтения  биты, которые указывают какое количество памяти или адресного пространства портов ввода/вывода размещено на плате и требуется отобразить в адресное пространство системы.
Во вторых, они содержат доступные для чтения и записи  биты предназначенные для хранения базовых адресов пространства памяти и портов ввода-вывода, выделенного устройству системой.
*/

//Константы для записи из printf
#define PRIMARY_BUS_NUMBER "Primary bus number: %#x\n"
#define SECONDARY_BUS_NUMBER "Secondary bus number: %#x\n"
#define SUBORDINATE_BUS_NUMBER "Subordinate bus number: %#x\n"

#define NO_DEVICE 0xFFFFFFFF //Если устройство отсутствует, то значение регистра будет равно этому числу
