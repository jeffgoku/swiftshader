LOCAL_PATH:= $(call my-dir)

COMMON_C_INCLUDES := \
	bionic \
	$(LOCAL_PATH)/../include \
	$(LOCAL_PATH)/../ \
	$(LOCAL_PATH)/../../ \
	$(LOCAL_PATH)/../../LLVM/include-android \
	$(LOCAL_PATH)/../../LLVM/include-linux \
	$(LOCAL_PATH)/../../LLVM/include \
	$(LOCAL_PATH)/../../LLVM/lib/Target/X86 \
	$(LOCAL_PATH)/../../Renderer/ \
	$(LOCAL_PATH)/../../Common/ \
	$(LOCAL_PATH)/../../Shader/ \
	$(LOCAL_PATH)/../../Main/

COMMON_CFLAGS := \
	-DLOG_TAG=\"swiftshader_compiler\" \
	-Wno-unused-parameter \
	-Wno-implicit-exception-spec-mismatch \
	-Wno-overloaded-virtual \
	-fno-operator-names \
	-msse2 \
	-D__STDC_CONSTANT_MACROS \
	-D__STDC_LIMIT_MACROS \
	-std=c++11 \
	-Xclang -fuse-init-array

COMMON_SRC_FILES := \
	preprocessor/Diagnostics.cpp \
	preprocessor/DirectiveHandler.cpp \
	preprocessor/DirectiveParser.cpp \
	preprocessor/ExpressionParser.cpp \
	preprocessor/Input.cpp \
	preprocessor/Lexer.cpp \
	preprocessor/Macro.cpp \
	preprocessor/MacroExpander.cpp \
	preprocessor/Preprocessor.cpp \
	preprocessor/Token.cpp \
	preprocessor/Tokenizer.cpp \
	AnalyzeCallDepth.cpp \
	Compiler.cpp \
	debug.cpp \
	Diagnostics.cpp \
	DirectiveHandler.cpp \
	glslang_lex.cpp \
	glslang_tab.cpp \
	InfoSink.cpp \
	Initialize.cpp \
	InitializeParseContext.cpp \
	IntermTraverse.cpp \
	Intermediate.cpp \
	intermOut.cpp \
	ossource_posix.cpp \
	OutputASM.cpp \
	parseConst.cpp \
	ParseHelper.cpp \
	PoolAlloc.cpp \
	SymbolTable.cpp \
	TranslatorASM.cpp \
	util.cpp \
	ValidateGlobalInitializer.cpp \
	ValidateLimitations.cpp \
	ValidateSwitch.cpp \

include $(CLEAR_VARS)
LOCAL_CLANG := true
LOCAL_MODULE := swiftshader_compiler_release
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(COMMON_SRC_FILES)
LOCAL_CFLAGS += \
	$(COMMON_CFLAGS) \
	-ffunction-sections \
	-fdata-sections \
	-DANGLE_DISABLE_TRACE
LOCAL_C_INCLUDES := $(COMMON_C_INCLUDES)
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_CLANG := true
LOCAL_MODULE := swiftshader_compiler_debug
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(COMMON_SRC_FILES)

LOCAL_CFLAGS += \
	$(COMMON_CFLAGS) \
	-UNDEBUG \
	-g \
	-O0

LOCAL_C_INCLUDES := $(COMMON_C_INCLUDES)
include $(BUILD_STATIC_LIBRARY)
