#pragma once

#include <filesystem>
#include <istream>
#include <vector>
#include <iostream>
#include <variant>
#include <fstream>
#include <string_view>

namespace omfl {
    const unsigned char ASCII_intervals[5][2] = {{'0', '9'},
                                                 {'A', 'Z'},
                                                 {'a', 'z'},
                                                 {'-', '-'},
                                                 {'_', '_'}};

    enum symbols {
        Numbers, BigLiter, LitleLiter, Tire, DownLine
    };
    enum types {
        STRING, INTEGER, FLOAT, BOLEAN, ARRAY, SECTION
    };

    class NewYear {
    public:
        class ArrayKey {
            friend NewYear;
        public:
            std::vector<unsigned char> type;
            std::vector<std::variant<std::string, int, float, bool, ArrayKey>> mass;
            std::string name_of_key;
        };

        class StringKey {
            friend NewYear;
            std::string name_of_key;
            std::string value;
        };

        class IntKey {
            friend NewYear;
            std::string name_of_key;
            int32_t value;
        };

        class FloatKey {
            friend NewYear;
            std::string name_of_key;
            float value;
        };

        class BoolKey {
            friend NewYear;
            std::string name_of_key;
            bool value;
        };

        class NewYearSection {
            friend NewYear;
            std::string name;
            std::vector<StringKey> string_keys;
            std::vector<ArrayKey> array_keys;
            std::vector<BoolKey> bool_keys;
            std::vector<IntKey> int_keys;
            std::vector<FloatKey> float_keys;
            std::vector<NewYearSection*> sub_sections;
        };

        class Node {
        public:
            unsigned char my_type;
            std::variant<std::string, int, float, bool, ArrayKey, StringKey, IntKey, FloatKey, BoolKey, NewYearSection*> typekey;
            bool key_or_zn = false;

            Node(unsigned char typee,
                 std::variant<std::string, int, float, bool, ArrayKey, StringKey, IntKey, FloatKey, BoolKey, NewYearSection*> keyy,
                 bool value = false)
                    : my_type(typee), typekey(keyy), key_or_zn(value) {
            }

            bool IsFloat() const {
                return my_type == FLOAT;
            }

            bool IsInt() const {
                return my_type == INTEGER;
            }

            bool IsString() const {
                return my_type == STRING;
            }

            bool IsBool() const {
                return my_type == BOLEAN;
            }

            bool IsArray() const {
                return my_type == ARRAY;
            }

            int32_t AsInt() const {
                if (IsInt()) {
                    if (key_or_zn == false) {
                        IntKey x = std::get<IntKey>(typekey);
                        return x.value;
                    }
                    return std::get<int>(typekey);

                }
                return 0;
            }

            std::string AsString() const {
                if (IsString()) {
                    if (key_or_zn == false) {
                        StringKey x = std::get<StringKey>(typekey);
                        return x.value;
                    }
                    return std::get<std::string>(typekey);
                }
                return "";
            }

            float AsFloat() const {
                if (IsFloat()) {
                    if (key_or_zn == false) {
                        FloatKey x = std::get<FloatKey>(typekey);
                        return x.value;
                    }
                    return std::get<float>(typekey);
                }
                return 0;
            }

            bool AsBool() const {
                if (IsBool()) {
                    if (key_or_zn == false) {
                        BoolKey x = std::get<BoolKey>(typekey);
                        return x.value;
                    }
                    return std::get<bool>(typekey);
                }
                return 0;
            }

            int32_t AsIntOrDefault(int32_t y) const {
                if (IsInt()) {
                    AsInt();
                }
                return y;
            }

            float AsFloatOrDefault(float y) const {
                if (IsFloat()) {
                    AsFloat();
                }
                return y;
            }

            const std::string& AsStringOrDefault(const std::string& y) const {
                if (IsString()) {
                    AsString();
                }
                return y;
            }

            const Node operator[](int32_t i) const;

            const Node Get(std::string name) const;
        };

        class Getter {
            friend NewYear;

            const Node GetterFromSection(const NewYear::NewYearSection* _sections, const std::string& param) const;
        };

        const bool valid() const {
            return okey;
        }

        void ChangeValid() {
            okey = (okey + 1) % 2;
        }

        bool CreateNewStringKey(const std::string& name, const std::string& _value,
                                const std::string& name_of_section);

        bool CreateNewIntKey(const std::string& name, int32_t _value,
                             const std::string& name_of_section);

        bool CreateNewFloatKey(const std::string& name, float _value,
                               const std::string& name_of_section);

        bool
        CreateNewBoolKey(const std::string& name, bool _value, const std::string& name_of_section);

        bool CreateNewArrayKey(const std::string& name,
                               std::vector<std::variant<std::string, int, float, bool, ArrayKey>> _value,
                               std::vector<uint8_t> _type, const std::string& name_of_section);

        NewYearSection* CreateNewSection(const std::string& name_of_section);

        NewYearSection* AddSubSection(const std::string& name_of_section, const std::string& name_of_podsection);

        const Node Get(const std::string& name) const;

        ~NewYear() {
            for (uint32_t i = 0; i < _sections.size(); i++) {
                delete _sections[i];
            }
        }

    private:
        NewYearSection _default_section;
        // дополнительные секции
        std::vector<NewYearSection*> _sections;
        // валидность
        bool okey = true;
    };

    std::vector<std::string_view> split_string(char sep, const std::string& str);

    bool checking_string(std::string_view& str, size_t lenghtt);

    bool checking_integer(std::string_view& str, size_t lenghtt);

    bool checking_float(std::string_view& str, size_t lenghtt);

    bool checking_bool(std::string_view& str, size_t lenghtt);

    bool checking_array(const std::string_view& str, size_t lenghtt,
                        std::vector<std::variant<std::string, int, float, bool, NewYear::ArrayKey>>& elem,
                        std::vector<uint8_t>& types);

    bool checking_section(std::string_view& str, size_t lenghtt);

    bool checking_key(std::string_view& str, size_t lenghtt);

    int64_t GetFirstLiterAfterSpaces(const std::string_view& line);

    int64_t GetLastLiterAfterSpaces(const std::string_view& line, size_t len);

    const NewYear* LineParse(std::string_view& line, NewYear& x, std::string& current_section);

    NewYear parse(const std::filesystem::path& path);

    NewYear parse(const std::string& str);

}// namespace