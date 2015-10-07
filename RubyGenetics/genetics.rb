class DNA
	def initialize(new_genes)
		@fitness = 0
		@genes = new_genes
	end
end

def get_random_genes (count)
	genes = Array.new(count)

	for i in 0...count
		genes[i] = (rand(122-97) + 97).chr
	end

	return genes
end

p get_random_genes(10)
dna = DNA.new(get_random_genes(10))