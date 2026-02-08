.PHONY: db

db:
	depends/sqlpp11/output/bin/sqlpp11-ddl2cpp -auto-id \
	src/tools/db/maindb.sql src/tools/db/maindb maindb