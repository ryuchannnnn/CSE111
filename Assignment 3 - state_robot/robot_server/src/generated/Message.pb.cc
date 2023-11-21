// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Message.proto

#include "Message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace small_world {
class SM_EventDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SM_Event>
      _instance;
} _SM_Event_default_instance_;
}  // namespace small_world
namespace protobuf_Message_2eproto {
static void InitDefaultsSM_Event() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::small_world::_SM_Event_default_instance_;
    new (ptr) ::small_world::SM_Event();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::small_world::SM_Event::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_SM_Event =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsSM_Event}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_SM_Event.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::small_world::SM_Event, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::small_world::SM_Event, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::small_world::SM_Event, event_type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::small_world::SM_Event, event_time_),
  0,
  1,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::small_world::SM_Event)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::small_world::_SM_Event_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "Message.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rMessage.proto\022\013small_world\"2\n\010SM_Event"
      "\022\022\n\nevent_type\030\001 \002(\t\022\022\n\nevent_time\030\002 \002(\004"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 80);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Message.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_Message_2eproto
namespace small_world {

// ===================================================================

void SM_Event::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SM_Event::kEventTypeFieldNumber;
const int SM_Event::kEventTimeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SM_Event::SM_Event()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_Message_2eproto::scc_info_SM_Event.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:small_world.SM_Event)
}
SM_Event::SM_Event(const SM_Event& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  event_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_event_type()) {
    event_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.event_type_);
  }
  event_time_ = from.event_time_;
  // @@protoc_insertion_point(copy_constructor:small_world.SM_Event)
}

void SM_Event::SharedCtor() {
  event_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  event_time_ = GOOGLE_ULONGLONG(0);
}

SM_Event::~SM_Event() {
  // @@protoc_insertion_point(destructor:small_world.SM_Event)
  SharedDtor();
}

void SM_Event::SharedDtor() {
  event_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SM_Event::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* SM_Event::descriptor() {
  ::protobuf_Message_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Message_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SM_Event& SM_Event::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_Message_2eproto::scc_info_SM_Event.base);
  return *internal_default_instance();
}


void SM_Event::Clear() {
// @@protoc_insertion_point(message_clear_start:small_world.SM_Event)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    event_type_.ClearNonDefaultToEmptyNoArena();
  }
  event_time_ = GOOGLE_ULONGLONG(0);
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool SM_Event::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:small_world.SM_Event)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string event_type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_event_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->event_type().data(), static_cast<int>(this->event_type().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "small_world.SM_Event.event_type");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint64 event_time = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_event_time();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &event_time_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:small_world.SM_Event)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:small_world.SM_Event)
  return false;
#undef DO_
}

void SM_Event::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:small_world.SM_Event)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string event_type = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->event_type().data(), static_cast<int>(this->event_type().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "small_world.SM_Event.event_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->event_type(), output);
  }

  // required uint64 event_time = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->event_time(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:small_world.SM_Event)
}

::google::protobuf::uint8* SM_Event::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:small_world.SM_Event)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string event_type = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->event_type().data(), static_cast<int>(this->event_type().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "small_world.SM_Event.event_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->event_type(), target);
  }

  // required uint64 event_time = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->event_time(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:small_world.SM_Event)
  return target;
}

size_t SM_Event::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:small_world.SM_Event)
  size_t total_size = 0;

  if (has_event_type()) {
    // required string event_type = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->event_type());
  }

  if (has_event_time()) {
    // required uint64 event_time = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->event_time());
  }

  return total_size;
}
size_t SM_Event::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:small_world.SM_Event)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required string event_type = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->event_type());

    // required uint64 event_time = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->event_time());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SM_Event::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:small_world.SM_Event)
  GOOGLE_DCHECK_NE(&from, this);
  const SM_Event* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SM_Event>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:small_world.SM_Event)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:small_world.SM_Event)
    MergeFrom(*source);
  }
}

void SM_Event::MergeFrom(const SM_Event& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:small_world.SM_Event)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_event_type();
      event_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.event_type_);
    }
    if (cached_has_bits & 0x00000002u) {
      event_time_ = from.event_time_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void SM_Event::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:small_world.SM_Event)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SM_Event::CopyFrom(const SM_Event& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:small_world.SM_Event)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SM_Event::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void SM_Event::Swap(SM_Event* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SM_Event::InternalSwap(SM_Event* other) {
  using std::swap;
  event_type_.Swap(&other->event_type_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(event_time_, other->event_time_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata SM_Event::GetMetadata() const {
  protobuf_Message_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Message_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace small_world
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::small_world::SM_Event* Arena::CreateMaybeMessage< ::small_world::SM_Event >(Arena* arena) {
  return Arena::CreateInternal< ::small_world::SM_Event >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
