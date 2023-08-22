#include "parser.h"

namespace omfl {


    bool NewYear::CreateNewStringKey(const std::string& name, const std::string& _value,
                                     const std::string& name_of_section) {
        if (name_of_section == "default_section!") {
            for (uint32_t i = 0; i < _default_section.string_keys.size(); i++) {
                // проверка на наличие такого ключа
                if (_default_section.string_keys[i].name_of_key == name) {
                    return false;
                }
                StringKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.string_keys.push_back(new_key);
                return true;
            }
            if (_default_section.string_keys.size() == 0) {
                StringKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.string_keys.push_back(new_key);
                return true;
            }
        } else {
            for (uint32_t i = 0; i < _sections.size(); i++) {
                if (_sections[i]->name == name_of_section) {
                    for (uint32_t j = 0; j < _sections[i]->string_keys.size(); j++) {
                        if (_sections[i]->string_keys[j].name_of_key == name) {
                            return false;
                        }
                    }
                    StringKey new_key;
                    new_key.name_of_key = name;
                    new_key.value = _value;
                    _sections[i]->string_keys.push_back(new_key);
                    return true;
                }

            }
            CreateNewStringKey(name, _value, CreateNewSection(name_of_section)->name);
        }
    }

    bool NewYear::CreateNewIntKey(const std::string& name, int32_t _value, const std::string& name_of_section) {
        if (name_of_section == "default_section!") {
            for (uint32_t i = 0; i < _default_section.int_keys.size(); i++) {
                // проверка на наличие такого ключа
                if (_default_section.int_keys[i].name_of_key == name) {
                    return false;
                }
                IntKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.int_keys.push_back(new_key);
                return true;
            }
            if (_default_section.int_keys.size() == 0) {
                IntKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.int_keys.push_back(new_key);
                return true;
            }
        } else {
            for (uint32_t i = 0; i < _sections.size(); i++) {
                if (_sections[i]->name == name_of_section) {
                    for (uint32_t j = 0; j < _sections[i]->int_keys.size(); j++) {
                        if (_sections[i]->int_keys[j].name_of_key == name) {
                            return false;
                        }
                    }
                    IntKey new_key;
                    new_key.name_of_key = name;
                    new_key.value = _value;
                    _sections[i]->int_keys.push_back(new_key);
                    return true;
                }

            }
            CreateNewIntKey(name, _value, CreateNewSection(name_of_section)->name);
        }
    }

    bool NewYear::CreateNewFloatKey(const std::string& name, float _value, const std::string& name_of_section) {
        if (name_of_section == "default_section!") {
            for (uint32_t i = 0; i < _default_section.float_keys.size(); i++) {
                // проверка на наличие такого ключа
                if (_default_section.float_keys[i].name_of_key == name) {
                    return false;
                }
                FloatKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.float_keys.push_back(new_key);
                return true;
            }
            if (_default_section.float_keys.size() == 0) {
                FloatKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.float_keys.push_back(new_key);
                return true;
            }
        } else {
            for (uint32_t i = 0; i < _sections.size(); i++) {
                if (_sections[i]->name == name_of_section) {
                    for (uint32_t j = 0; j < _sections[i]->float_keys.size(); j++) {
                        if (_sections[i]->float_keys[j].name_of_key == name) {
                            return false;
                        }
                    }
                    FloatKey new_key;
                    new_key.name_of_key = name;
                    new_key.value = _value;
                    _sections[i]->float_keys.push_back(new_key);
                    return true;
                }

            }
            CreateNewFloatKey(name, _value, CreateNewSection(name_of_section)->name);
        }
    }

    bool NewYear::CreateNewBoolKey(const std::string& name, bool _value, const std::string& name_of_section) {
        if (name_of_section == "default_section!") {
            for (uint32_t i = 0; i < _default_section.bool_keys.size(); i++) {
                // проверка на наличие такого ключа
                if (_default_section.bool_keys[i].name_of_key == name) {
                    return false;
                }
                BoolKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.bool_keys.push_back(new_key);
                return true;
            }
            if (_default_section.bool_keys.size() == 0) {
                BoolKey new_key;
                new_key.name_of_key = name;
                new_key.value = _value;
                _default_section.bool_keys.push_back(new_key);
                return true;
            }
        } else {
            for (uint32_t i = 0; i < _sections.size(); i++) {
                if (_sections[i]->name == name_of_section) {
                    for (uint32_t j = 0; j < _sections[i]->bool_keys.size(); j++) {
                        if (_sections[i]->bool_keys[j].name_of_key == name) {
                            return false;
                        }
                    }
                    BoolKey new_key;
                    new_key.name_of_key = name;
                    new_key.value = _value;
                    _sections[i]->bool_keys.push_back(new_key);
                    return true;
                }
            }
            CreateNewBoolKey(name, _value, CreateNewSection(name_of_section)->name);
        }
    }

    bool NewYear::CreateNewArrayKey(const std::string& name,
                                    std::vector<std::variant<std::string, int, float, bool, ArrayKey>> _value,
                                    std::vector<uint8_t> _type, const std::string& name_of_section) {
        if (name_of_section == "default_section!") {
            for (uint32_t i = 0; i < _default_section.array_keys.size(); i++) {
                // проверка на наличие такого ключа
                if (_default_section.array_keys[i].name_of_key == name) {
                    return false;
                }
                ArrayKey new_key;
                new_key.name_of_key = name;
                new_key.mass = _value;
                new_key.type = _type;
                _default_section.array_keys.push_back(new_key);
                return true;
            }
            if (_default_section.array_keys.size() == 0) {
                ArrayKey new_key;
                new_key.name_of_key = name;
                new_key.mass = _value;
                new_key.type = _type;
                _default_section.array_keys.push_back(new_key);
                return true;
            }
        } else {
            for (uint32_t i = 0; i < _sections.size(); i++) {
                if (_sections[i]->name == name_of_section) {
                    for (uint32_t j = 0; j < _sections[i]->array_keys.size(); j++) {
                        if (_sections[i]->array_keys[j].name_of_key == name) {
                            return false;
                        }
                    }
                    ArrayKey new_key;
                    new_key.name_of_key = name;
                    new_key.mass = _value;
                    new_key.type = _type;
                    _sections[i]->array_keys.push_back(new_key);
                    return true;
                }

            }
            CreateNewArrayKey(name, _value, _type, CreateNewSection(name_of_section)->name);
        }
    }

    NewYear::NewYearSection* NewYear::CreateNewSection(const std::string& name_of_section) {
        for (uint32_t i = 0; i < _sections.size(); i++) {
            if (_sections[i]->name == name_of_section) {
                return _sections[i];
            }
        }
        size_t index = name_of_section.find('.');
        if (index != std::string::npos) {
            CreateNewSection(name_of_section.substr(0, index));
            return AddSubSection(name_of_section.substr(0, index), name_of_section.substr(index + 1));

        }
        NewYearSection* x = new NewYearSection;
        x->name = name_of_section;
        _sections.push_back(x);
        return x;
    }

    NewYear::NewYearSection*
    NewYear::AddSubSection(const std::string& name_of_section, const std::string& name_of_podsection) {
        for (uint32_t i = 0; i < _sections.size(); i++) {
            if (_sections[i]->name == (name_of_section + '.' + name_of_podsection)) {
                return _sections[i];
            }
        }
        for (uint32_t i = 0; i < _sections.size(); i++) {
            if (_sections[i]->name == name_of_section) {
                NewYearSection* x = new NewYearSection;
                x->name = name_of_section + '.' + name_of_podsection;
                _sections.push_back(x);
                _sections[i]->sub_sections.push_back(_sections[_sections.size() - 1]);
                return _sections[_sections.size() - 1];
            }
        }
        NewYearSection* parent = CreateNewSection(name_of_section);
        return AddSubSection(parent->name, name_of_podsection);
    }

    const NewYear::Node NewYear::Get(const std::string& name) const {
        size_t index_of_point = name.find('.');
        // секцииияяяя
        if (index_of_point != std::string::npos) {
            // секция это, или обращение к ключу в этой секции?
            for (size_t j = 0; j < _sections.size(); j++) {
                if (_sections[j]->name == name) {
                    return Node(SECTION, _sections[j]);
                }
            }
            // все таки обращение по ключу
            index_of_point = name.rfind('.');
            std::string name_of_section = name.substr(0, index_of_point);
            std::string param = name.substr(index_of_point + 1);

            for (size_t j = 0; j < _sections.size(); j++) {
                if (_sections[j]->name == name_of_section) {
                    Getter get_section;
                    return get_section.GetterFromSection(_sections[j], param);
                }
            }
        }
            // все еще возможно секция
        else {
            // сначала проверим есть ли секция с таким именем
            for (size_t j = 0; j < _sections.size(); j++) {
                if (_sections[j]->name == name) {
                    return Node(SECTION, _sections[j]);
                }
            }
            Getter get_section;
            return get_section.GetterFromSection(&_default_section, name);
        }
    }

    bool checking_key(std::string_view& str, size_t lenghtt) {
        if (lenghtt == 0) {
            return false;
        }

        int64_t left = GetFirstLiterAfterSpaces(str);
        if (left == -1) {
            return false;
        }
        int64_t right = GetLastLiterAfterSpaces(str, lenghtt);
        if (right == -1) {
            return false;
        }

        // нулевая длина параметра
        if (right - left == 1) {
            return false;
        }

        for (uint32_t k = left; k <= right; k++) {
            bool flag_valid = false;
            // проверка на допустимые символы
            for (int j = 0; j < 5; j++) {
                if ((static_cast<int>(str[k]) >= ASCII_intervals[j][0] &&
                     static_cast<int>(str[k]) <= ASCII_intervals[j][1])) {
                    flag_valid = true;
                    break;
                }
            }
            if (flag_valid == false) {
                return false;
            }
        }
        str = str.substr(left, right - left + 1);
        return true;
    }

    std::vector<std::string_view> split_string(char sep, const std::string& str) {
        std::vector<std::string_view> for_ans;
        std::string_view friend_str{str};
        uint64_t len = str.length();
        uint64_t q = 0;
        while (str[q] == sep) {
            q++;
            if (q == len) {
                return for_ans;
            }
        }
        for (uint64_t p = q; p < len; p++) {
            if (str[p] == sep && p != q) {
                for_ans.push_back(friend_str.substr(q, p - q));
                q = p;
                while (str[q] == sep) {
                    q++;
                    if (q == len) {
                        return for_ans;
                    }
                }
                p = q;
            }
        }
        for_ans.push_back(friend_str.substr(q));
        return for_ans;
    }

    bool checking_string(std::string_view& str, size_t lenghtt) {
        if (lenghtt == 0) {
            return false;
        }
        int64_t left = GetFirstLiterAfterSpaces(str);
        if (left == -1) {
            return false;
        }
        if (str[left] != '\"') {
            return false;
        }
        int64_t right = GetLastLiterAfterSpaces(str, lenghtt);
        if (right == -1) {
            return false;
        }
        if (str[right] != '\"') {
            return false;
        }
        str = str.substr(left + 1, right - left - 1);
        if (str.find('\"') != std::string::npos) {
            return false;
        }
        return true;
    }

    bool checking_integer(std::string_view& str, size_t lenghtt) {
        if (lenghtt == 0) {
            return false;
        }
        int64_t iter = GetFirstLiterAfterSpaces(str);
        if (iter == -1) {
            return false;
        }
        int64_t iter2 = GetLastLiterAfterSpaces(str, lenghtt);
        if (iter2 == -1) {
            return false;
        }
        bool zn = false;

        if (str[iter] == '+' || str[iter] == '-') {
            zn = true;
            if (iter == lenghtt - 1) {
                return false;
            }
            iter++;
        }
        for (uint32_t i = iter; i <= iter2; i++) {
            if (!(static_cast<int>(str[i]) >= ASCII_intervals[Numbers][0] &&
                  static_cast<int>(str[i]) <= ASCII_intervals[Numbers][1])) {
                return false;
            }
        }
        if (zn) {
            iter--;
        }
        str = str.substr(iter, iter2 - iter + 1);
        return true;
    }

    bool checking_float(std::string_view& str, size_t lenghtt) {
        if (lenghtt == 0) {
            return false;
        }
        int64_t left = GetFirstLiterAfterSpaces(str);
        if (left == -1) {
            return false;
        }

        int64_t right = GetLastLiterAfterSpaces(str, lenghtt);
        if (right == -1) {
            return false;
        }

        size_t index_of_point = str.find('.');
        // нет точки
        if (index_of_point == std::string::npos) {
            return false;
        }
        std::string_view first_part = str.substr(0, index_of_point);
        std::string_view last_part = str.substr(index_of_point + 1);
        if (checking_integer(first_part, index_of_point) && checking_integer(last_part, lenghtt - index_of_point - 1)) {
            str = str.substr(left, right - left + 1);
            return true;
        }
        return false;
    }

    bool checking_bool(std::string_view& str, size_t lenghtt) {
        if (lenghtt == 0) {
            return false;
        }
        int64_t iter = GetFirstLiterAfterSpaces(str);
        if (iter == -1) {
            return false;
        }
        if (str[iter] == 't') {
            if (iter + 4 > lenghtt) {
                return false;
            }
            if (str.substr(iter, 4) == "true") {
                // проверка на символы после
                for (uint32_t l = iter + 4; l < lenghtt; l++) {
                    if (str[l] != ' ') {
                        return false;
                    }
                }
                str = str.substr(iter, 4);
                return true;
            } else {
                return false;
            }
        } else if (str[iter] == 'f') {
            if (iter + 5 > lenghtt) {
                return false;
            }
            if (str.substr(iter, 5) == "false") {
                for (uint32_t l = iter + 5; l < lenghtt; l++) {
                    if (str[l] != ' ') {
                        return false;
                    }
                }
                str = str.substr(iter, 5);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool checking_array(const std::string_view& str, size_t lenghtt,
                        std::vector<std::variant<std::string, int, float, bool, NewYear::ArrayKey>>& elem,
                        std::vector<uint8_t>& types) {
        if (lenghtt == 0) {
            return false;
        }
        int64_t left = GetFirstLiterAfterSpaces(str);
        if (left == -1) {
            return false;
        }
        if (str[left] != '[') {
            return false;
        }

        int64_t right = GetLastLiterAfterSpaces(str, lenghtt);
        if (right == -1) {
            return -1;
        }
        if (str[right] != ']') {
            return false;
        }

        // пустой массив
        if (right - left == 1) {
            return true;
        }
        uint32_t count_open = 0;
        uint32_t count_close = 0;

        std::vector<std::string_view> elements;

        uint32_t right_srez = left + 1;
        uint32_t left_srez = 0;

        for (uint32_t i = left + 1; i < right; i++) {
            if (str[i] == ',' && count_open == count_close) {
                if (right_srez > left_srez) {
                    return false;
                }
                elements.push_back(str.substr(right_srez, left_srez - right_srez + 1));
                right_srez = i + 1;
            } else if (str[i] == ']') {
                count_close++;
                if (count_close > count_open) {
                    return false;
                }
                left_srez = i;
            } else if (str[i] == '[') {
                count_open++;
                left_srez = i;
            } else {
                left_srez = i;
            }
        }
        if (right_srez > left_srez) {
            return false;
        }
        elements.push_back(str.substr(right_srez, left_srez - right_srez + 1));

        for (uint32_t i = 0; i < elements.size(); i++) {
            size_t lenn = elements[i].length();
            if (checking_string(elements[i], lenn)) {
                elem.push_back(static_cast<std::string>(elements[i]));
                types.push_back(STRING);
            } else if (checking_integer(elements[i], lenn)) {
                elem.push_back(std::stoi(static_cast<std::string>(elements[i])));
                types.push_back(INTEGER);
            } else if (checking_float(elements[i], lenn)) {
                elem.push_back(std::stof(static_cast<std::string>(elements[i])));
                types.push_back(FLOAT);
            } else if (checking_bool(elements[i], lenn)) {
                if (elements[i] == "true") {
                    elem.push_back(true);
                } else {
                    elem.push_back(false);
                }

                types.push_back(BOLEAN);
            } else {
                std::vector<std::variant<std::string, int, float, bool, NewYear::ArrayKey>> elem2;
                std::vector<uint8_t> types2;
                if (checking_array(elements[i], lenn, elem2, types2)) {
                    NewYear::ArrayKey arr;
                    arr.type = types2;
                    arr.mass = elem2;
                    elem.push_back(arr);
                    types.push_back(ARRAY);
                } else {
                    return false;
                }
            }
        }
        return true;
    }


    bool checking_section(std::string_view& str, size_t lenghtt) {
        if (lenghtt == 0) {
            return false;
        }
        int64_t left = GetFirstLiterAfterSpaces(str);
        if (left == -1) {
            return false;
        }
        if (str[left] != '[') {
            return false;
        }

        int64_t right = GetLastLiterAfterSpaces(str, lenghtt);
        if (right == -1) {
            return -1;
        }
        if (str[right] != ']') {
            return false;
        }

        // между скобками пусто
        if (right - left == 1) {
            return false;
        }

        for (uint32_t i = left + 1; i < right; i++) {
            if (str[i] == '.') {
                if (i == left + 1 || i == right - 1) {
                    return false;
                }
                continue;
            } else if (str[i] == ' ') {
                continue;
            } else {
                bool flag_valid = false;
                // проверка на допустимые символы
                for (int j = 0; j < 5; j++) {
                    if ((static_cast<int>(str[i]) >= ASCII_intervals[j][0] &&
                         static_cast<int>(str[i]) <= ASCII_intervals[j][1])) {
                        flag_valid = true;
                        break;
                    }
                }
                if (!flag_valid) {
                    return false;
                }
            }
        }
        str = str.substr(left + 1, right - left - 1);
        return true;
    }

    // возвращает -1 если строка полностью состоит из пробелов
    int64_t GetFirstLiterAfterSpaces(const std::string_view& line) {
        uint32_t iter = 0;
        while (line[iter] == ' ') {
            iter++;
            // пустая строка
            if (iter == line.length()) {
                return -1;
            }
        }
        return iter;
    }

    // возвращает -1 если строка полностью состоит из пробелов
    int64_t GetLastLiterAfterSpaces(const std::string_view& line, size_t len) {
        uint32_t iter = len - 1;
        while (line[iter] == ' ') {
            iter--;
            // пустая строка
            if (iter == 0) {
                return -1;
            }
        }
        return iter;
    }

    const NewYear* LineParse(std::string_view& line, NewYear& x, std::string& current_section) {
        if (line.length() == 0) {
            return nullptr;
        }
        int64_t left = GetFirstLiterAfterSpaces(line);
        if (left == -1) {
            x.ChangeValid();
            return &x;
        }
        // строка-комментарий
        if (line[left] == '#') {
            return nullptr;
        }

        size_t index_of_comment = line.find('#');
        if (index_of_comment != std::string::npos) {
            line = line.substr(0, index_of_comment);
        }

        size_t lenghttt = line.length();
        size_t index = line.find('=');

        // Нет знака равно
        if (index == std::string::npos) {
            //секция
            if (!checking_section(line, lenghttt)) {
                x.ChangeValid();
                return &x;
            }
            current_section = line;
            size_t index_of_point = line.rfind('.');
            if (index_of_point == std::string::npos) {
                x.CreateNewSection(static_cast<std::string>(line));
            } else {
                x.AddSubSection(static_cast<std::string>(line.substr(0, index_of_point)),
                                static_cast<std::string>(line.substr(index_of_point + 1)));
            }
            return nullptr;
        }

        // нулевая длина ключа
        if (index == 0) {
            x.ChangeValid();
            return &x;
        }
        // после '=' пусто
        if (index == line.length() - 1) {
            x.ChangeValid();
            return &x;
        }

        std::string_view name_of_param = line.substr(left, index - left);
        if (!checking_key(name_of_param, index - left)) {
            x.ChangeValid();
            return &x;
        }

        std::string_view value_of_param = line.substr(index + 1);
        uint32_t len_of_value = value_of_param.length();

        int64_t first_element_of_value = GetFirstLiterAfterSpaces(value_of_param);
        if (first_element_of_value == -1) {
            x.ChangeValid();
            return &x;
        }

        if (value_of_param[first_element_of_value] == '[') {
            // проверка на массив
            std::vector<std::variant<std::string, int, float, bool, NewYear::ArrayKey>> elem2;
            std::vector<uint8_t> types2;
            if (!checking_array(value_of_param, len_of_value, elem2, types2)) {
                x.ChangeValid();
                return &x;
            } else {
                if (!x.CreateNewArrayKey(static_cast<std::string>(name_of_param), elem2, types2, current_section)) {
                    x.ChangeValid();
                    return &x;
                }
                return nullptr;
            }
        }
        if (value_of_param[first_element_of_value] == '"') {
            // проверка на строку
            if (!checking_string(value_of_param, len_of_value)) {
                x.ChangeValid();
                return &x;
            } else {
                if (!x.CreateNewStringKey(static_cast<std::string>(name_of_param),
                                          static_cast<std::string>(value_of_param), current_section)) {
                    x.ChangeValid();
                    return &x;
                }
                return nullptr;
            }
        }

        if (checking_integer(value_of_param, len_of_value)) {
            if (!x.CreateNewIntKey(static_cast<std::string>(name_of_param),
                                   std::stoi(static_cast<std::string>(value_of_param)), current_section)) {
                x.ChangeValid();
                return &x;
            }
            return nullptr;
        } else if (checking_float(value_of_param, len_of_value)) {
            if (!x.CreateNewFloatKey(static_cast<std::string>(name_of_param),
                                     std::stof(static_cast<std::string>(value_of_param)), current_section)) {
                x.ChangeValid();
                return &x;
            }
            return nullptr;
        } else if (checking_bool(value_of_param, len_of_value)) {
            bool zn;
            if (value_of_param == "true") {
                zn = true;
            } else if (value_of_param == "false") {
                zn = false;
            }
            if (!x.CreateNewBoolKey(static_cast<std::string>(name_of_param), zn, current_section)) {
                x.ChangeValid();
                return &x;
            }
            return nullptr;
        } else {
            x.ChangeValid();
            return &x;
        }
    }

    NewYear parse(const std::string& str) {
        NewYear x;
        std::vector<std::string_view> lines = split_string('\n', str);
        std::string current_section = "default_section!";

        for (uint32_t line = 0; line < lines.size(); line++) {
            if (LineParse(lines[line], x, current_section) == nullptr) {
                continue;
            }
            if (x.valid() == false) {
                return x;
            }
        }
        return x;
    };

    NewYear parse(const std::filesystem::path& path) {
        std::ifstream fin(path);
        if (!fin.is_open()) {
            std::cerr << " Ошибка открытия файла " << path;
            exit(1);
        }
        NewYear x;
        std::string current_section = "default_section!";
        std::string line;
        while (getline(fin, line)) {
            std::string_view line_another{line};
            if (LineParse(line_another, x, current_section) == nullptr) {
                continue;
            };
            if (!x.valid()) {
                return x;
            }
        }
        return x;
    }

    const NewYear::Node
    NewYear::Getter::GetterFromSection(const NewYear::NewYearSection* _sections, const std::string& param) const {
        for (size_t i = 0; i < _sections->string_keys.size(); i++) {
            if (_sections->string_keys[i].name_of_key == param) {
                return Node(STRING, _sections->string_keys[i]);
            }
        }
        for (size_t i = 0; i < _sections->int_keys.size(); i++) {
            if (_sections->int_keys[i].name_of_key == param) {
                return Node(INTEGER, _sections->int_keys[i]);
            }
        }
        for (size_t i = 0; i < _sections->bool_keys.size(); i++) {
            if (_sections->bool_keys[i].name_of_key == param) {
                return Node(BOLEAN, _sections->bool_keys[i]);
            }
        }
        for (size_t i = 0; i < _sections->float_keys.size(); i++) {
            if (_sections->float_keys[i].name_of_key == param) {
                return Node(FLOAT, _sections->float_keys[i]);
            }
        }
        for (size_t i = 0; i < _sections->array_keys.size(); i++) {
            if (_sections->array_keys[i].name_of_key == param) {
                return Node(ARRAY, _sections->array_keys[i]);
            }
        }
        // явно ошибка какая-то
        // Undefined behavior (заполняем x мусором)
        return Node(INTEGER, 0, true);
    }

    const NewYear::Node NewYear::Node::operator[](int32_t i) const {
        if (my_type == ARRAY) {
            ArrayKey x = std::get<ArrayKey>(typekey);

            if (((x.mass)).size() <= i) {
                return Node(my_type, typekey);
            }

            unsigned char temp_type = ((x.type))[i];

            if (temp_type == ARRAY) {
                return Node(temp_type, std::get<ArrayKey>((((x.mass))[i])));
            } else {
                switch (temp_type) {
                    case STRING:
                        return Node(temp_type, std::get<std::string>(((x.mass))[i]), true);
                    case INTEGER:
                        return Node(temp_type, std::get<int>(((x.mass))[i]), true);
                    case FLOAT:
                        return Node(temp_type, std::get<float>(((x.mass))[i]), true);
                    case BOLEAN:
                        return Node(temp_type, std::get<bool>(((x.mass))[i]), true);
                }
            }
        }
        return Node(my_type, typekey);
    }

    const NewYear::Node NewYear::Node::Get(std::string name) const {
        if (my_type == SECTION) {
            NewYearSection* x = std::get<NewYearSection*>(typekey);
            std::string full_name = x->name + '.' + name;
            for (uint32_t i = 0; i < (x->sub_sections).size(); i++) {
                if ((x->sub_sections)[i]->name == full_name) {
                    return Node(SECTION, (x->sub_sections)[i]);
                }
            }
            Getter get_section;
            return get_section.GetterFromSection(x, name);
        }
        return Node(my_type, typekey);
    }
}

