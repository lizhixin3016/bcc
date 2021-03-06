/*
 * Copyright (c) 2015 PLUMgrid, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <memory>
#include <string>
#include <unistd.h>
#include <vector>

namespace ebpf {

// debug flags
enum {
  // Debug output compiled LLVM IR.
  DEBUG_LLVM_IR = 0x1,
  // Debug output loaded BPF bytecode and register state on branches.
  DEBUG_BPF = 0x2,
  // Debug output pre-processor result.
  DEBUG_PREPROCESSOR = 0x4,
  // Debug output ASM instructions embedded with source.
  DEBUG_SOURCE = 0x8,
  // Debug output register state on all instructions in addition to DEBUG_BPF.
  DEBUG_BPF_REGISTER_STATE = 0x16,
};

template <class T, class... Args>
typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

std::vector<int> get_online_cpus();

std::vector<int> get_possible_cpus();

std::string get_pid_exe(pid_t pid);

}  // namespace ebpf
