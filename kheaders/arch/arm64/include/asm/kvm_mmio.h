

#ifndef __ARM64_KVM_MMIO_H__
#define __ARM64_KVM_MMIO_H__

#include <linux/kvm_host.h>
#include <asm/kvm_arm.h>

struct kvm_decode {
	unsigned long rt;
	bool sign_extend;
	
	bool sixty_four;
};

void kvm_mmio_write_buf(void *buf, unsigned int len, unsigned long data);
unsigned long kvm_mmio_read_buf(const void *buf, unsigned int len);

int kvm_handle_mmio_return(struct kvm_vcpu *vcpu, struct kvm_run *run);
int io_mem_abort(struct kvm_vcpu *vcpu, struct kvm_run *run,
		 phys_addr_t fault_ipa);

#endif	
