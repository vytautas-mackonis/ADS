#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void shuffle_file(const std::string &input_file, const std::string &output_file);
std::vector<std::string> read_lines(const std::string &file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <input_file> <outputfile>" << std::endl;
        return 0;
    }

    try {
        shuffle_file(argv[1], argv[2]);
    } catch (const std::ifstream::failure& e) {
        std::cerr << "Exception happened: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}

std::vector<std::string> read_lines(const std::string &filename) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);
    file.open(filename);

    std::vector<std::string> result;

    std::string line;
    while (std::getline(file, line)) {
        result.push_back(line);
    }

    return result;
}

void write_lines(const std::vector<std::string> &lines, const std::string &filename) {
    std::ofstream file;
    file.exceptions(std::ofstream::badbit);
    file.open(filename);

    for (auto it = lines.begin(); it != lines.end(); ++it) {
        file << *it << std::endl;
    }
}

void shuffle_vector(std::vector<std::string> &v) {
    srand(time(NULL));

    for (auto i = v.size(); i-- > 0; ) {
        unsigned lucky_index = rand() % (i+ 1);
        std::swap(v[i], v[lucky_index]);
    }
}

void shuffle_file(const std::string &input_file, const std::string &output_file) {
    auto lines = read_lines(input_file);
    shuffle_vector(lines);
    write_lines(lines, output_file);
}
