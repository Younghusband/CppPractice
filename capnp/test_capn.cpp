//
// #include <iostream>
// #include <string>
// #include <vector>
// #include <chrono>
// #include <capnp/serialize.h>
// #include <sys/resource.h>
// #include "Struct.capnp.h"
//
// const int num = 100000;
//
// std::vector<long long>run1() {
// 	std::vector<capnp::MallocMessageBuilder> vm(num);
// 	std::vector<LscInfo::Builder>vb;
//
// 	auto start1 = std::chrono::high_resolution_clock::now();
// 	for (int i = 0; i < num; ++i) {
// 		LscInfo::Builder lscInfo = vm[i].initRoot<LscInfo>();
//     	lscInfo.setModuleName("LscInfo " + std::to_string(i));
//     	lscInfo.setLscXGrad({1, 1, 1});
//     	lscInfo.setLscYGrad({1, 1, 1});
//     	lscInfo.setLscXSize({1, 1, 1});
//     	lscInfo.setLscYSize({1, 1, 1});
// 	}
// 	auto start2 = std::chrono::high_resolution_clock::now();
// 	std::vector<kj::Array<capnp::word>> ret;
// 	for(int i=0;i<num;++i) {
// 		ret.push_back(std::move(capnp::messageToFlatArray(vm[i])));
// 	}
//
// 	auto start3 = std::chrono::high_resolution_clock::now();
// 	for(int i=0;i<num;++i) {
// 		auto encoded_array_ptr = ret[i].asChars();
// 		auto encoded_char_array = encoded_array_ptr.begin();
// 		auto size = encoded_array_ptr.size();
//
// 		auto received_array = kj::ArrayPtr<capnp::word>(reinterpret_cast<capnp::word*>(encoded_char_array), size/sizeof(capnp::word));
// 		::capnp::FlatArrayMessageReader message_receiver_builder(received_array);
// 		auto message_receiver = message_receiver_builder.getRoot<LscInfo>();
// 	}
//
// 	auto start4 = std::chrono::high_resolution_clock::now();
// 	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(start2 - start1).count();
// 	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(start3 - start1).count();
// 	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(start4 - start3).count();
// 	std::cout << duration2 << ',' << duration3 << std::endl;
// 	struct rusage usage;
// 	getrusage(RUSAGE_SELF, &usage);
//     std::cout << "Memory usage: " << usage.ru_maxrss << "KB" << std::endl;
// 	return {duration2, duration3, usage.ru_maxrss};
// }
//
// std::vector<long long>run() {
// 	capnp::MallocMessageBuilder messageBuilder;
// 	std::vector<LscInfo::Builder>vb;
// 	auto start1 = std::chrono::high_resolution_clock::now();
// 	for (int i = 0; i < num; ++i) {
// 		LscInfo::Builder lscInfo = messageBuilder.initRoot<LscInfo>();
//     	lscInfo.setModuleName("LscInfo " + std::to_string(i));
//     	lscInfo.setLscXGrad({1, 1, 1});
//     	lscInfo.setLscYGrad({1, 1, 1});
//     	lscInfo.setLscXSize({1, 1, 1});
//     	lscInfo.setLscYSize({1, 1, 1});
// 	}
// 	kj::Array<capnp::word> encoded_array = capnp::messageToFlatArray(messageBuilder);
// 	auto encoded_array_ptr = encoded_array.asChars();
// 	auto encoded_char_array = encoded_array_ptr.begin();
// 	auto size = encoded_array_ptr.size();
// 	auto start2 = std::chrono::high_resolution_clock::now();
// 	auto received_array = kj::ArrayPtr<capnp::word>(reinterpret_cast<capnp::word*>(encoded_char_array), size/sizeof(capnp::word));
// 	::capnp::FlatArrayMessageReader message_receiver_builder(received_array);
// 	for (int i=0;i<num;++i) {
// 		auto message_receiver = message_receiver_builder.getRoot<LscInfo>();
// 		//if(i == 10) std::cout << message_receiver.getModuleName().cStr() << std::endl;
// 	}
//
// 	//std::cout << message_receiver[0].getModuleName().cStr() << std::endl;
// 	auto start3 = std::chrono::high_resolution_clock::now();
// 	auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(start2 - start1).count();
// 	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(start3 - start2).count();
// 	//std::cout << duration1 << ',' << duration2 << std::endl;
// 	struct rusage usage;
// 	getrusage(RUSAGE_SELF, &usage);
//     //std::cout << "Memory usage: " << usage.ru_maxrss << "KB" << std::endl;
// 	return {duration1, duration2, usage.ru_maxrss};
//
// }
//
//
// int main() {
// 	int times = 10;
// 	long long sum[3] = {0,0,0};
// 	long long maxm = 0;
// 	for (int i=0;i<times;i++) {
// 		auto res = run();
// 		sum[0] += res[0];
// 		sum[1] += res[1];
// 		sum[2] += res[2];
// 		maxm = std::max(maxm, res[2]);
// 	}
// 	std::cout << "serialize Execution time: " << sum[0] / times << " microseconds" << std::endl;
// 	std::cout << "deserialize Execution time: " << sum[1] / times << " microseconds" << std::endl;
// 	std::cout << "average Memory usage: " << sum[2] / times << " KB" << std::endl;
// 	std::cout << "Max Memory usage: " << maxm << " KB" << std::endl;
//     return 0;
// }
