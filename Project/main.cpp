#define _CRT_SECURE_NO_WARNINGS
#include <atomic>
#include <cstdio>
#include <cstring>
#include <future>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <openssl/sha.h>

struct sha256 {
	unsigned char digest[SHA256_DIGEST_LENGTH];
	void compute(const char* str, int len) {
		SHA256((const unsigned char*)str, len, digest);
	}
	bool parse(const std::string& hash) {
		if (hash.length() != 2 * SHA256_DIGEST_LENGTH) {
			std::cerr << "Invalid SHA-256 hash\n";
			return false;
		}
		const char* p = hash.c_str();
		for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i, p += 2) {
			unsigned int x;
			if (sscanf(p, "%2x", &x) != 1) {
				std::cerr << "Cannot parse SHA-256 hash\n";
				return false;
			}
			digest[i] = x;
		}
		return true;
	}
};

bool operator==(const sha256& a, const sha256& b) {
	return memcmp(a.digest, b.digest, SHA256_DIGEST_LENGTH) == 0;
}

bool next_password(std::string& passwd, size_t start) {
	size_t len = passwd.length();
	for (size_t i = len - 1; i >= start; --i) {
		char c = passwd[i];
		if (c < 'z') {
			++passwd[i];
			return true;
		}
		passwd[i] = 'a';
	}
	return false;
}

class password_finder {
public:
	password_finder(int);
	bool find_passwords(const std::vector<std::string>&);
private:
	int length;
	void find_passwords(char);
	std::vector<std::string> hashes;
	std::vector<sha256> digests;
	std::atomic<size_t> count;
};

password_finder::password_finder(int len) : length(len) {}

void password_finder::find_passwords(char ch) {
	std::string passwd(length, 'a');
	passwd[0] = ch;
	sha256 digest;
	while (count > 0) {
		digest.compute(passwd.c_str(), length);
		for (int m = 0; m < hashes.size(); ++m) {
			if (digest == digests[m]) {
				--count;
				std::ostringstream out;
				out << "password: " << passwd << ", hash: " << hashes[m] << '\n';
				std::cout << out.str();
				break;
			}
		}
		if (!next_password(passwd, 1))
			break;
	}
}

bool password_finder::find_passwords(const std::vector<std::string>& h) {
	hashes = h;
	digests.resize(hashes.size());
	for (int i = 0; i < hashes.size(); ++i) {
		if (!digests[i].parse(hashes[i]))
			return false;
	}
	count = hashes.size();
	std::vector<std::future<void>> futures;
	const int n = 26;
	for (int i = 0; i < n; ++i) {
		char c = 'a' + i;
		futures.push_back(std::async(std::launch::async,
			[&, c]() { find_passwords(c); }));
	}
	return true;
}

void sha256_string(char* string, char outputBuffer[65])
{
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, string, strlen(string));
	SHA256_Final(hash, &sha256);
	int i = 0;
	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
	}
	outputBuffer[64] = 0;
}

//"1115dd800feaacefdf481f1f9070374a2a81e27880f187396db67958b207cbad"
//"74e1bb62f8dabb8125a58852b63bdf6eaef667cb56ac7f7cdba6d7305c50a22f"

int main() {
	char buffer[65];
	sha256_string((char*)"apple", buffer);
	printf("%s\n", buffer);


	std::vector<std::string> hashes{ buffer };


	int iter = 1;

	while (true) {
		password_finder pf(iter);
		pf.find_passwords(hashes);
		iter++;
		if (iter == 10)
			break;
	}
	return 0;
}